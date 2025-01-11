#ifndef COMATH_H
#define COMATH_H

#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <cctype> // for std::isdigit

// 定义 point 结构体，用于存储字符和数字
struct point {
    char chr;  // 存储运算符或 '0'（表示数字）
    double num; // 存储数字
};

// 定义 computer 类，用于解析和计算表达式
class computer {
public:
    std::string str; // 存储输入的表达式
    void cmin(); // 输入表达式并输出
    double calculateExpression(); // 计算表达式的值

private:
    std::list<point> myList; // 存储解析后的表达式
    void DividedtoPoint(); // 将表达式解析为数字和运算符
    double toFaValue(std::list<point>& st); // 计算无括号表达式的值
};

#endif // COMATH_H