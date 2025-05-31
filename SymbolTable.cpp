#include "SymbolTable.hpp"

SymbolTable::SymbolTable() : currentLevel(0), nextAddress(0) {}

void SymbolTable::addSymbol(const Symbol& sym) {
    for (const auto& s : symbols) {
        if (s.name == sym.name && s.level == currentLevel) {
            fprintf(stderr, "符号重复定义: %s\n", sym.name.c_str());
            exit(1);
        }
    }
    symbols.push_back(sym);
}

Symbol* SymbolTable::findSymbol(const std::string& name) {
    for (int i = symbols.size() - 1; i >= 0; --i) {
        if (symbols[i].name == name) return &symbols[i];
    }
    return nullptr;
}

void SymbolTable::addStruct(const StructType& st) {
    for (const auto& s : structs) {
        if (s.name == st.name) {
            fprintf(stderr, "结构体重复定义: %s\n", st.name.c_str());
            exit(1);
        }
    }
    structs.push_back(st);
}

StructType* SymbolTable::findStruct(const std::string& name) {
    for (auto& st : structs) {
        if (st.name == name) return &st;
    }
    return nullptr;
}

void SymbolTable::enterScope() {
    currentLevel++;
}

void SymbolTable::leaveScope() {
    symbols.erase(
        std::remove_if(symbols.begin(), symbols.end(),
            [&](const Symbol& sym) {
                return sym.level == currentLevel;
            }),
        symbols.end()
    );
    currentLevel--;
}

int SymbolTable::allocateAddress() {
    return nextAddress++;
}

int SymbolTable::getCurrentOffset() { 
    return nextAddress;
}

void SymbolTable::resetAddress() {
    nextAddress = 0;
}

void SymbolTable::dump() {
    printf("===== 符号表 DUMP =====\n");
    for (const auto& s : symbols) {
        printf("Name: %s, Kind: %d, Type: %d, Level: %d, Addr: %d\n",
            s.name.c_str(), (int)s.kind, (int)s.type, s.level, s.address);
    }
    for (const auto& st : structs) {
        printf("Struct: %s {\n", st.name.c_str());
        for (const auto& field : st.fields) {
            printf("  %s: %d\n", field.first.c_str(), (int)field.second);
        }
        printf("}\n");
    }
    printf("========================\n");
}
