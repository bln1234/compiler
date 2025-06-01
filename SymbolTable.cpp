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

void SymbolTable::dump(std::ostream& out) {
    out << "===== 符号表 DUMP =====" << std::endl;
    for (const auto& s : symbols) {
        out << "Name: " << s.name
            << ", Kind: " << static_cast<int>(s.kind)
            << ", Type: " << static_cast<int>(s.type)
            << ", Level: " << s.level
            << ", Addr: " << s.address << std::endl;
    }
    for (const auto& st : structs) {
        out << "Struct: " << st.name << " {" << std::endl;
        for (const auto& field : st.fields) {
            out << "  " << field.first << ": " << static_cast<int>(field.second) << std::endl;
        }
        out << "}" << std::endl;
    }
    out << "========================" << std::endl;
}
