#ifndef VM_H
#define VM_H
#pragma once
#include <vector>
#include <iostream>

enum Fct {
    lit, opr, lod, sto, cal, ini, jmp, jpc
};

struct Instruction {
    Fct f;
    int l;
    int a;
    Instruction(Fct f, int l, int a) : f(f), l(l), a(a) {}
};

class VM {
public:
    VM(const std::vector<Instruction>& code);
    void interpret(std::ostream& out);

private:
    int base(int l, int b);
    std::vector<Instruction> code;
    static const int stacksize = 1000;
    int s[stacksize];
};

#endif
