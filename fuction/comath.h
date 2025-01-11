#ifndef COMATH_H
#define COMATH_H

#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <cctype> // for std::isdigit

// ���� point �ṹ�壬���ڴ洢�ַ�������
struct point {
    char chr;  // �洢������� '0'����ʾ���֣�
    double num; // �洢����
};

// ���� computer �࣬���ڽ����ͼ�����ʽ
class computer {
public:
    std::string str; // �洢����ı��ʽ
    void cmin(); // ������ʽ�����
    double calculateExpression(); // ������ʽ��ֵ

private:
    std::list<point> myList; // �洢������ı��ʽ
    void DividedtoPoint(); // �����ʽ����Ϊ���ֺ������
    double toFaValue(std::list<point>& st); // ���������ű��ʽ��ֵ
};

#endif // COMATH_H