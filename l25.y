%{
#include <vector>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "SymbolTable.hpp"
#include "VM.hpp"

void yyerror(const char *s);
int yylex(void);

std::vector<Instruction> code;
int level = 0;  // 当前嵌套层级
int blockStartIndex;
int mainEntryIndex = 0;
SymbolTable symtab;
int addressOffset = 0;  // 当前作用域内的偏移地址
%}

%union {
    int num;
    char *id;
    std::string* str;
    std::vector<int>* numlist;
}
%type <numlist> number_list

%token <num> NUMBER
%token <id> IDENT
%token PROGRAM FUNC MAIN RETURN LET IF ELSE WHILE INPUT OUTPUT STRUCT_DEF STRUCT
%token EQ NEQ LEQ GEQ LT GT ASSIGN PLUS MINUS MUL DIV
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COMMA SEMICOLON DOT
%start program

%%

program:
    PROGRAM IDENT LBRACE struct_def_list func_def main_block RBRACE
    {
        code[0].a = mainEntryIndex;
    }
    ;

struct_def_list:
    /* empty */
    | struct_def_list struct_def_stmt
    ;

struct_def_stmt:
    STRUCT_DEF IDENT LBRACE struct_member_list RBRACE SEMICOLON
    {
        printf("Struct definition: %s\n", $2);
    }
    ;

struct_member_list:
    /* empty */
    | struct_member_list declare_stmt SEMICOLON
    ;

func_def:
    /* empty */
    | func_def func
    ;

func:
    FUNC IDENT LPAREN param_list RPAREN LBRACE stmt_list RETURN expr SEMICOLON RBRACE 
    {
        // 添加函数信息到符号表
    
    }
    | FUNC IDENT LPAREN RPAREN LBRACE stmt_list RETURN expr SEMICOLON RBRACE 
    {
        printf("Parsed function without param: %s\n", $2);
    }
    ;

main_block:
    MAIN
    {
        mainEntryIndex = code.size();
    }
    block
    {
        code.push_back(Instruction(jmp, 0, 0));
    }
    ;

param_list:
    IDENT
    | param_list COMMA IDENT
    ;

stmt_list:
    stmt SEMICOLON
    | stmt_list stmt SEMICOLON
    ;

stmt:
    declare_stmt
    | array_declare_stmt
    | struct_declare_stmt
    | assign_stmt
    | if_stmt
    | while_stmt
    | input_stmt
    | output_stmt
    | func_call
    ;

struct_declare_stmt:
    STRUCT IDENT IDENT ASSIGN LBRACE struct_init_list RBRACE
    {
        
    }
    | STRUCT IDENT IDENT
    {
        printf("Declare struct variable: %s of type %s\n", $3, $2);
    }
    ;

struct_init_list:
    expr
    | struct_init_list COMMA expr
    ;

array_declare_stmt:
    LBRACKET NUMBER RBRACKET IDENT ASSIGN LBRACE number_list RBRACE
    {
        int length = $2;
        char* name = $4;
        std::vector<int>* vals = $7;

        // 1. 检查数组长度是否匹配
        if ((int)vals->size() != length) {
            fprintf(stderr, "数组初始化长度与声明长度不匹配: %s\n", name);
            exit(1);
        }

        // 2. 向符号表添加数组符号
        Symbol sym(name, SymbolKind::ARRAY, ValueType::Integer, level, symtab.allocateAddress(), length);
        symtab.addSymbol(sym);

        // 3. 生成初始化数组的p-code
        int baseAddr = sym.address;
        for (int i = 0; i < length; ++i) {
            code.push_back(Instruction(lit, 0, (*vals)[i])); 
            code.push_back(Instruction(sto, 0, baseAddr + i));
        }

        // 4. 释放临时vector
        delete vals;
    }
    ;

number_list:
    NUMBER
    {
        $$ = new std::vector<int>();
        $$->push_back($1);
    }
    | number_list COMMA NUMBER
    {
        $$ = $1;
        $$->push_back($3);
    }
    ;

declare_stmt:
    LET IDENT
    {
        int addr = symtab.allocateAddress();
        symtab.addSymbol(Symbol($2, SymbolKind::Variable, ValueType::Integer, level, addr));
    }
    | LET IDENT ASSIGN expr
    {
        int addr = symtab.allocateAddress();
        symtab.addSymbol(Symbol($2, SymbolKind::Variable, ValueType::Integer, level, addr));
        // 赋值 expr 的值在栈顶
        code.push_back(Instruction(sto, level, addr));
    }
    ;

assign_stmt:
    IDENT ASSIGN expr
    {
        Symbol* sym = symtab.findSymbol($1);
        if (!sym) {
            fprintf(stderr, "Undefined Variable: %s\n", $1);
            exit(1);
        }
        if (sym->kind != SymbolKind::Variable) {
            fprintf(stderr, "%s is noy Variable\n", $1);
            exit(1);
        }

        // expr 的值已在栈顶
        // 将其存储到变量地址
        code.push_back(Instruction(sto, level - sym->level, sym->address));
    }
    | IDENT DOT IDENT ASSIGN expr
    {   
    }
    | IDENT LBRACKET expr RBRACKET ASSIGN expr
    {
        Symbol* sym = symtab.findSymbol($1);
        if (!sym) {
            fprintf(stderr, "Undefined Array: %s\n", $1);
            exit(1);
        }
        if (sym->kind != SymbolKind::ARRAY) {
            fprintf(stderr, "%s is not Array\n", $1);
            exit(1);
        }

        // 两个 expr：前一个是索引，后一个是值
        // 它们的值会依次在栈上（值在顶，索引在次顶）

        // 先交换栈顶两个元素，使得栈顶是索引，次顶是值
        code.push_back(Instruction(opr, 0, 17)); // opr 20 是 swap

        // 加载基址
        code.push_back(Instruction(lit, 0, sym->address));

        // 加上索引
        code.push_back(Instruction(opr, 0, 2));  // 加法

        // 存储到目标地址（数组[i] = val）
        code.push_back(Instruction(stoi, 0, 0)); // 假设 `stoi` 表示间接存储指令
    }
    ;


if_stmt:
    IF LPAREN bool_expr RPAREN block
    | IF LPAREN bool_expr RPAREN block ELSE block
    ;

while_stmt:
    WHILE LPAREN bool_expr RPAREN block
    {
        printf("While stmt\n");
    }
    ;

input_stmt:
    INPUT LPAREN ident_list RPAREN
    {
        printf("Input stmt\n");
    }
    ;

output_stmt:
    OUTPUT LPAREN expr_list RPAREN
    {
        code.push_back(Instruction(opr, 0, 15));
    }
    ;

func_call:
    IDENT LPAREN arg_list RPAREN
    {
        printf("Function call: %s\n", $1);
    }
    | IDENT LPAREN RPAREN
    {
        printf("Function call (no args): %s\n", $1);
    }
    ;

arg_list:
    expr
    | arg_list COMMA expr
    ;

expr_list:
    expr
    {
        code.push_back(Instruction(opr, 0, 14));
    }
    | expr_list COMMA expr
    {
        code.push_back(Instruction(opr, 0, 14));
    }
    ;

ident_list:
    IDENT
    | ident_list COMMA IDENT
    ;

bool_expr:
    expr EQ expr
    {
        code.push_back(Instruction(opr, 0, 8));  // ==
    }
    | expr NEQ expr
    {
        code.push_back(Instruction(opr, 0, 9));  // !=
    }
    | expr LT expr
    {
        code.push_back(Instruction(opr, 0, 10)); // <
    }
    | expr GEQ expr
    {
        code.push_back(Instruction(opr, 0, 11)); // >=
    }
    | expr GT expr
    {
        code.push_back(Instruction(opr, 0, 12)); // >
    }
    | expr LEQ expr
    {
        code.push_back(Instruction(opr, 0, 13)); // <=
    }
;

expr:
    PLUS term
    | MINUS term
    {
        code.push_back(Instruction(opr, 0, 1)); //取负
    }
    | term
    | expr PLUS term
    {
        code.push_back(Instruction(opr, 0, 2));  // 加法
    }
    | expr MINUS term
    {
        code.push_back(Instruction(opr, 0, 3));  // 减法
    }
    ;

term:
    term MUL factor
    {
        code.push_back(Instruction(opr, 0, 4));  // 乘法
    }
    | term DIV factor
    {
        code.push_back(Instruction(opr, 0, 5));  // 除法
    }
    | factor
    ;

factor:
    IDENT
    {
        Symbol* sym = symtab.findSymbol($1);
        if(!sym) {
            fprintf(stderr, "Undefined Variable: %s\n", $1);
            exit(1);
        }
        code.push_back(Instruction(lod, sym->level, sym->address));
    }
    | IDENT DOT IDENT                          { printf("Struct member access: %s.%s\n", $1, $3); }
    | IDENT LBRACKET expr RBRACKET
    {
        Symbol* sym = symtab.findSymbol($1);
        if (!sym) {
            fprintf(stderr, "未定义的数组变量: %s\n", $1);
            exit(1);
        }
        if (sym->kind != SymbolKind::ARRAY) {
            fprintf(stderr, "变量 %s 不是数组类型\n", $1);
            exit(1);
        }
        // 生成数组访问的 p-code
        // expr 的结果已经在栈顶
        // 加载数组基地址
        code.push_back(Instruction(lit, 0, sym->address));
        // 加上索引
        code.push_back(Instruction(opr, 0, 2));
        // 加载数组元素的值
        code.push_back(Instruction(ind, 0, 0));
    }
    | NUMBER
    {
        code.push_back(Instruction(lit, 0, $1));
    }
    | LPAREN expr RPAREN
    | func_call
    ;

block:
    LBRACE
    {
        symtab.enterScope();
        symtab.resetAddress();
        code.push_back(Instruction(ini, 0, 0));  // 临时，地址数稍后回填
        blockStartIndex = code.size() - 1;
    }
    stmt_list
    RBRACE
    {
        int localSize = symtab.getCurrentOffset(); // 获取当前作用域变量个数
        code[blockStartIndex].a = localSize;
        symtab.leaveScope();
    }
    ;

%%
extern FILE *yyin;  // 声明 Flex 的输入流变量

void yyerror(const char *s) {
    fprintf(stderr, "error: %s\n", s);
}

std::string getFctName(Fct f) {
    switch (f) {
        case lit: return "lit";
        case opr: return "opr";
        case lod: return "lod";
        case sto: return "sto";
        case cal: return "cal";
        case ini: return "ini";
        case jmp: return "jmp";
        case jpc: return "jpc";
        case ind: return "ind";
        case stoi: return "stoi";
        default: return "???";
    }
}

void outputCodeToFile(const std::vector<Instruction>& code) {
    for (size_t i = 0; i < code.size(); ++i) {
        const Instruction& instr = code[i];
        printf("%s %d %d\n", getFctName(instr.f).c_str(), instr.l, instr.a);
    }
}

int main(int argc, char **argv) {
    FILE *input = fopen("test.l25", "r");   // 输入文件
    if (!input) {
        perror("打开输入文件失败");
        return 1;
    }

    yyin = input; // 设置 Flex 输入流

    FILE *output = freopen("p-code.txt", "w", stdout);  // 重定向 stdout 到文件
    if (!output) {
        perror("打开输出文件失败");
        return 1;
    }
    code.push_back(Instruction(jmp, 0, 0));
    yyparse();  // 解析开始
    outputCodeToFile(code);
    VM vm(code);
    std::ofstream fout("fout.txt");
    vm.interpret(fout);
    fclose(input);
    fclose(output);
    std::ofstream symout("symtable.txt");
    symtab.dump(symout);
    return 0;
}