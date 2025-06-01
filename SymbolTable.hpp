#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

enum class SymbolKind { Variable, Function, Struct, ARRAY };
enum class ValueType { Integer, String, StructType, Array };

struct Symbol {
    std::string name;
    SymbolKind kind;
    ValueType type;
    int level;                    // 作用域层级
    int address;                  // 相对地址
    int length;                 //数组长度
    std::vector<ValueType> paramTypes; // 函数参数类型

    Symbol(std::string name, SymbolKind kind, ValueType type,
           int level, int address,int length = 0)
        : name(name), kind(kind), type(type), level(level), address(address),length(length) {}
};

struct StructType {
    std::string name;
    std::vector<std::pair<std::string, ValueType>> fields;

    StructType(std::string name) : name(std::move(name)) {}
};

class SymbolTable {
public:
    SymbolTable();

    void addSymbol(const Symbol& sym);
    Symbol* findSymbol(const std::string& name);
    void addStruct(const StructType& st);
    StructType* findStruct(const std::string& name);

    void enterScope();
    void leaveScope();
    int allocateAddress();
    int getCurrentOffset();
    void resetAddress();
    void dump();

private:
    std::vector<Symbol> symbols;
    std::vector<StructType> structs;
    int currentLevel;
    int nextAddress;
};

#endif // SYMBOL_TABLE_HPP
