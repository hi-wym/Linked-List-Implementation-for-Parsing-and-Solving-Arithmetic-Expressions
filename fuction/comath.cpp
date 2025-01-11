#include "comath.h"

// ������ʽ�����
void computer::cmin() {
    std::cin >> computer::str;
    std::cout << computer::str;
}

// �����ֺ��������������
void putInList(std::list<point>& list, double num, const char chr) {
    point pt;
    pt.chr = chr;
    pt.num = num;
    list.push_back(pt);
}

// �������ʽΪ���ֺ������
void computer::DividedtoPoint() {
    double current_number = 0; // ��ǰ����������
    bool is_number = false;    // ����Ƿ����ڽ�������

    for (char c : computer::str) {
        if (std::isdigit(c)) {
            // ���ַ�ת��Ϊ���ֲ��ۼӵ���ǰ������
            current_number = current_number * 10 + (c - '0');
            is_number = true;
        }
        else {
            // ���֮ǰ���ڽ������֣������ִ�������
            if (is_number) {
                putInList(computer::myList, current_number, '0');
                current_number = 0; // ���õ�ǰ����
                is_number = false;  // ������ֽ�������
            }

            // ��������ַ������� +, -, *, / �ȣ�
            putInList(computer::myList, 0, c);
        }
    }

    // �����ַ���ĩβ�����֣�������ڣ�
    if (is_number) {
        putInList(computer::myList, current_number, '0');
    }
}

// ���������ű��ʽ��ֵ
double computer::toFaValue(std::list<point>& list) {
    // �˷�����
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->chr == '*') {
            auto prev = std::prev(it);
            auto next = std::next(it);
            double result = prev->num * next->num;
            prev->num = result;
            list.erase(it);
            list.erase(next);
            it = prev; // ���õ�����
        }
    }

    // ����
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->chr == '/') {
            auto prev = std::prev(it);
            auto next = std::next(it);
            double result = prev->num / next->num;
            prev->num = result;
            list.erase(it);
            list.erase(next);
            it = prev; // ���õ�����
        }
    }

    // �ӷ�
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->chr == '+') {
            auto prev = std::prev(it);
            auto next = std::next(it);
            double result = prev->num + next->num;
            prev->num = result;
            list.erase(it);
            list.erase(next);
            it = prev; // ���õ�����
        }
    }

    // ����
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->chr == '-') {
            auto prev = std::prev(it);
            auto next = std::next(it);
            double result = prev->num - next->num;
            prev->num = result;
            list.erase(it);
            list.erase(next);
            it = prev; // ���õ�����
        }
    }

    // �������ս��
    return list.begin()->num;
}

// ������ʽ��ֵ��֧�����ţ�
double computer::calculateExpression() {
    // �������ʽ������
    DividedtoPoint();

    // ��������
    std::list<point> tempList; // ��ʱ�������ڴ洢��ǰ�����ڵı��ʽ
    std::stack<std::list<point>> stack; // ջ�����ڴ洢������ı��ʽ

    for (const auto& pt : myList) {
        if (pt.chr == '(') {
            // ���������ţ�����ǰ����ѹ��ջ���������ʱ����
            stack.push(tempList);
            tempList.clear();
        }
        else if (pt.chr == ')') {
            // ���������ţ����������ڵı��ʽ���������������ʱ����
            double subResult = toFaValue(tempList);
            tempList = stack.top(); // �ָ������������
            stack.pop();
            putInList(tempList, subResult, '0'); // ����������������
        }
        else {
            // ��ͨ�ַ���ֱ�Ӵ�����ʱ����
            tempList.push_back(pt);
        }
    }

    // �������ս��
    return toFaValue(tempList);
}