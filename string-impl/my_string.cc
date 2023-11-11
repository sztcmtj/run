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
    if (s == nullptr) {
        String();
        return;
    }

    int len = strlen(s);
    if (len == 0) {
        String();
        return;
    }

    this->len = len;
    str = new char[len + 1]; // 别忘了新建数组
    strcpy(this->str, s);
}

String::~String() {
    delete[] this->str;
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

String& String::operator+=(const String& s) {
    String tmp(*this);
    delete[] this->str;
    this->str = new char[this->len + s.len];
    stpcpy(this->str, tmp.str);
    stpcpy(this->str + this->len, s.str);
    this->len += s.len;
    return *this;
    // tmp自动析构
}

bool operator==(const String& s1, const String& s2) {
    return (strcmp(s1.str, s2.str) == 0);
}

bool operator<(const String& s1, const String& s2) {
    return (strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String& s1, const String& s2) {
    return (strcmp(s1.str, s2.str) > 0);
}

char& String::operator[](int index) {
    return str[index];
}

const char& String::operator[](int index) const {
    return str[index];
}

std::ostream& operator<<(std::ostream& os, String& s) {
    os << s.str;
    return os;
}