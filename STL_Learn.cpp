#include "comath.h"

int main() {
    computer comp;
    comp.cmin(); // 输入表达式

    double result = comp.calculateExpression(); // 计算表达式的值
    std::cout << "Result: " << result << std::endl; // 输出结果

    return 0;
}