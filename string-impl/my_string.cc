#include "my_string.h"
#include <cstring>

String::String() {
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const String& s) {
    if (s.len == 0) {
        String();
        return;
    }

    this->str = new char[s.len + 1]; // 切记+1！
    strcpy(this->str, s.str);
    this->len = s.len;
}

String::String(const char* s) {
    int len = strlen(s);
    if (len == 0) {
        String();
        return;
    }

    this->len = len;
    strcpy(this->str, s);
}

String& String::operator=(const String& s) {
    if (this == &s) {
        return *this;
    }

    delete[] this->str;
    this->len = s.len;
    this->str = new char[this->len + 1]; 
    strcpy(this->str, s.str);
    return *this;
}

String& String::operator=(const char* s) {
    delete[] this->str;
    this->len = strlen(s);
    this->str = new char[this->len + 1]; 
    strcpy(this->str, s);
    return *this;
}

String::~String() {
    delete[] this->str;
    this->len = 0;
}

String& String::operator+=(const String& s) {
    String tmp(s);
    delete[] this->str;
    this->str = new char[this->len + s.len];
    stpcpy(this->str, tmp.str);
    stpcpy(this->str + this->len, s.str);
    this->len += s.len;
    return *this;
    // tmp自动析构
}

std::ostream& operator<<(std::ostream& os, String& s) {
    os << s.str;
    return os;
}