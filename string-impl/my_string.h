#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>

// https://www.cnblogs.com/foghorn/p/14947986.html
class String {
public:
    // 构造函数
    String();
    String(const String& s);
    String(const char* s);

    // 析构函数
    ~String();

    // 操作符重载
    String& operator=(const String& s);
    String& operator=(const char* s);
    String& operator+=(const String& s);
    friend int operator==(const String& s1, const String& s2);
    friend int operator==(const String& s1, const String& s2);
    friend int operator==(const String& s1, const String& s2);
    char& operator[](int index);
    const char& operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& os, String& s);
    friend std::istream& operator>>(std::istream& is, String& s);

    // 普通成员函数
    int length() const;
private:
    int len;
    char* str;
};


#endif