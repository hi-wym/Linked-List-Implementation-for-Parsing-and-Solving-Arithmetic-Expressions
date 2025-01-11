#include "comath.h"

// 输入表达式并输出
void computer::cmin() {
    std::cin >> computer::str;
    std::cout << computer::str;
}

// 将数字和运算符存入链表
void putInList(std::list<point>& list, double num, const char chr) {
    point pt;
    pt.chr = chr;
    pt.num = num;
    list.push_back(pt);
}

// 解析表达式为数字和运算符
void computer::DividedtoPoint() {
    double current_number = 0; // 当前解析的数字
    bool is_number = false;    // 标记是否正在解析数字

    for (char c : computer::str) {
        if (std::isdigit(c)) {
            // 将字符转换为数字并累加到当前数字中
            current_number = current_number * 10 + (c - '0');
            is_number = true;
        }
        else {
            // 如果之前正在解析数字，则将数字存入链表
            if (is_number) {
                putInList(computer::myList, current_number, '0');
                current_number = 0; // 重置当前数字
                is_number = false;  // 标记数字解析结束
            }

            // 存放运算字符（例如 +, -, *, / 等）
            putInList(computer::myList, 0, c);
        }
    }

    // 处理字符串末尾的数字（如果存在）
    if (is_number) {
        putInList(computer::myList, current_number, '0');
    }
}

// 计算无括号表达式的值
double computer::toFaValue(std::list<point>& list) {
    // 乘法优先
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->chr == '*') {
            auto prev = std::prev(it);
            auto next = std::next(it);
            double result = prev->num * next->num;
            prev->num = result;
            list.erase(it);
            list.erase(next);
            it = prev; // 重置迭代器
        }
    }

    // 除法
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->chr == '/') {
            auto prev = std::prev(it);
            auto next = std::next(it);
            double result = prev->num / next->num;
            prev->num = result;
            list.erase(it);
            list.erase(next);
            it = prev; // 重置迭代器
        }
    }

    // 加法
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->chr == '+') {
            auto prev = std::prev(it);
            auto next = std::next(it);
            double result = prev->num + next->num;
            prev->num = result;
            list.erase(it);
            list.erase(next);
            it = prev; // 重置迭代器
        }
    }

    // 减法
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->chr == '-') {
            auto prev = std::prev(it);
            auto next = std::next(it);
            double result = prev->num - next->num;
            prev->num = result;
            list.erase(it);
            list.erase(next);
            it = prev; // 重置迭代器
        }
    }

    // 返回最终结果
    return list.begin()->num;
}

// 计算表达式的值（支持括号）
double computer::calculateExpression() {
    // 解析表达式到链表
    DividedtoPoint();

    // 处理括号
    std::list<point> tempList; // 临时链表，用于存储当前括号内的表达式
    std::stack<std::list<point>> stack; // 栈，用于存储括号外的表达式

    for (const auto& pt : myList) {
        if (pt.chr == '(') {
            // 遇到左括号，将当前链表压入栈，并清空临时链表
            stack.push(tempList);
            tempList.clear();
        }
        else if (pt.chr == ')') {
            // 遇到右括号，计算括号内的表达式，并将结果存入临时链表
            double subResult = toFaValue(tempList);
            tempList = stack.top(); // 恢复括号外的链表
            stack.pop();
            putInList(tempList, subResult, '0'); // 将计算结果存入链表
        }
        else {
            // 普通字符，直接存入临时链表
            tempList.push_back(pt);
        }
    }

    // 计算最终结果
    return toFaValue(tempList);
}