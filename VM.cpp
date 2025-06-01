#include "VM.hpp"

VM::VM(const std::vector<Instruction>& code) : code(code) {}

int VM::base(int l, int b) {
    int b1 = b;
    while (l > 0) {
        b1 = s[b1];
        l--;
    }
    return b1;
}

void VM::interpret(std::ostream& out) {
    int p = 0, b = 1, t = 0, swap;
    out << "Start pl0\n";
    s[0] = 0; s[1] = 0; s[2] = 0; s[3] = 0;

    do {
        Instruction i = code[p++];
        switch(i.f) {
            case lit:
                s[++t] = i.a;
                break;
            case opr:
                switch(i.a) {
                    case 0: /* 函数调用结束后返回 */
                        t = b - 1;
                        p = s[t + 3];
                        b = s[t + 2];
                        break;
                    case 1: /* 栈顶元素取反 */
                        s[t] = -s[t];
                        break;
                    case 2: /* 次栈顶项加上栈顶项，退两个栈元素，相加值进栈 */
                        t = t - 1;
                        s[t] = s[t] + s[t + 1];
                        break;
                    case 3:/* 次栈顶项减去栈顶项 */
                        t = t - 1;
                        s[t] = s[t] - s[t + 1];
                        break;
                    case 4:/* 次栈顶项乘以栈顶项 */
                        t = t - 1;
                        s[t] = s[t] * s[t + 1];
                        break;
                    case 5:/* 次栈顶项除以栈顶项 */
                        t = t - 1;
                        s[t] = s[t] / s[t + 1];
                        break;
                    case 6:/* 栈顶元素的奇偶判断 */
                        s[t] = s[t] % 2;
                        break;
                    case 8:/* 次栈顶项与栈顶项是否相等 */
                        t = t - 1;
                        s[t] = (s[t] == s[t + 1]);
                        break;
                    case 9:/* 次栈顶项与栈顶项是否不等 */
                        t = t - 1;
                        s[t] = (s[t] != s[t + 1]);
                        break;
                    case 10:/* 次栈顶项是否小于栈顶项 */
                        t = t - 1;
                        s[t] = (s[t] < s[t + 1]);
                        break;
                    case 11:/* 次栈顶项是否大于等于栈顶项 */
                        t = t - 1;
                        s[t] = (s[t] >= s[t + 1]);
                        break;
                    case 12:/* 次栈顶项是否大于栈顶项 */
                        t = t - 1;
                        s[t] = (s[t] > s[t + 1]);
                        break;
                    case 13: /* 次栈顶项是否小于等于栈顶项 */
                        t = t - 1;
                        s[t] = (s[t] <= s[t + 1]);
                        break;
                    case 14: /* 栈顶值输出 */
                        out << s[t--] << " ";
                        break;
                    case 15: /* 输出换行符 */
                        out << "\n";
                        break;
                    case 16: /* 读入一个输入置于栈顶 */
                        out << "? ";
                        int input;
                        std::cin >> input;
                        s[++t] = input;
                        break;
                    case 17: /* 交换栈顶的两个元素*/
                        swap = s[t];
                        s[t - 1] = swap;
                        s[t] = s[t - 1];
                }
                break;
            case lod:
                s[++t] = s[base(i.l, b) + i.a];
                break;
            case sto:
                s[base(i.l, b) + i.a] = s[t--];
                break;
            case cal:
                s[t + 1] = base(i.l, b);
                s[t + 2] = b;
                s[t + 3] = p;
                b = t + 1;
                p = i.a;
                break;
            case ini:
                t += i.a;
                break;
            case jmp:
                p = i.a;
                break;
            case jpc:
                if (s[t--] == 0) p = i.a;
                break;
            case ind:
                s[t] = s[s[t]];
                break;
            case stoi:
                s[s[t]] = s[t - 1];
                t = t - 2;
                break;
        }
    } while (p != 0);

    out << "End\n";
}
