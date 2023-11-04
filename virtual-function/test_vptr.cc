#include <iostream>

class Base {
public:
    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    }
    virtual void g() {
        std::cout << "Base::g()" << std::endl;
    }
    virtual void h() {
        std::cout << "Base::h()" << std::endl;
    }
};

class Base2 {
public:
    virtual void f() {
        std::cout << "Base2::f()" << std::endl;
    }
    virtual void g() {
        std::cout << "Base2::g()" << std::endl;
    }
    virtual void h() {
        std::cout << "Base2::h()" << std::endl;
    }
};

typedef void(*Fun)(void); // 定义函数指针类型Fun

class DerivedCommon : public Base {
public:
    void virtual f1() {
        std::cout << "DerivedCommon::f1()" << std::endl;
    }

    void virtual g1() {
        std::cout << "DerivedCommon::g1()" << std::endl;
    }

    void virtual h1() {
        std::cout << "DerivedCommon::h1()" << std::endl;
    }
}; // 一般继承，无虚函数覆盖

class DerivedCover : public Base {
public:
    void virtual f() {
        std::cout << "DerivedCommon::f1()" << std::endl;
    }

    void virtual g1() {
        std::cout << "DerivedCommon::g1()" << std::endl;
    }

    void virtual h1() {
        std::cout << "DerivedCommon::h1()" << std::endl;
    }
}; // 有函数重写的继承

class DerivedMultiple : public Base, Base2 {
public:
    void virtual f1() {
        std::cout << "DerivedMultiple::f1()" << std::endl;
    }

    void virtual g1() {
        std::cout << "DerivedMultiple::g1()" << std::endl;
    }
};

// 基类虚表结构
void testBase() {
    std::cout << "基类虚表结构" << std::endl;
    Base b;
    Fun pFun = NULL;
    std::cout << "虚表地址:[" << (long*)(&b) << "]" << std::endl; // 这里不转成long类型也没事
    std::cout << "虚表第一个函数的地址:[" << (long*)*((long*)(&b)) << "]" << std::endl; // 最左边转成long*的目的是取虚表第一项
    pFun = (Fun)*(long*)*((long*)(&b)); // 虚表里面存的是函数地址，取第0项，则是把Base::f1()的地址拿到，这就是第一个星号的作用
    pFun();
    pFun = (Fun)*((long*)*((long*)(&b)) + 1); // 取虚表第二项所指向的函数
    pFun();
    pFun = (Fun)*((long*)*((long*)(&b)) + 2);
    pFun();
}

// 子类虚函数表
void testDerivedCommon() {
    std::cout << "子类虚表结构" << std::endl;
    DerivedCommon d;
    Fun pFun = NULL;
    std::cout << "虚表地址:[" << (long*)(&d) << "]" << std::endl; // 这里不转成long类型也没事
    std::cout << "虚表第一个函数的地址:[" << (long*)*((long*)(&d)) << "]" << std::endl; // 最左边转成long*的目的是取虚表第一项
    pFun = (Fun)*(long*)*((long*)(&d)); // 虚表里面存的是函数地址，取第0项，则是把Base::f1()的地址拿到，这就是第一个星号的作用
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 1); // 取虚表第二项所指向的函数
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 2);
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 3);
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 4);
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 5);
    pFun();
}

void testDerivedMultiple() {
    std::cout << "多继承虚表结构" << std::endl;
    DerivedMultiple d;
    Fun pFun = NULL;
    std::cout << "虚表地址:[" << (long*)(&d) << "]" << std::endl; // 这里不转成long类型也没事
    std::cout << "虚表第一个函数的地址:[" << (long*)*((long*)(&d)) << "]" << std::endl; // 最左边转成long*的目的是取虚表第一项
    // 以下是Base1的虚表函数
    pFun = (Fun)*(long*)*((long*)(&d)); 
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 1); 
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 2);
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 3);
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 4);
    pFun();
    // 以下是Base2的虚表函数
    pFun = (Fun)*((long*)*((long*)(&d) + 1));
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d) + 1) + 1);
    pFun();
}

// 子类虚函数表
void testDerivedCover() {
    std::cout << "子类虚表结构" << std::endl;
    DerivedCover d;
    Fun pFun = NULL;
    std::cout << "虚表地址:[" << (long*)(&d) << "]" << std::endl; // 这里不转成long类型也没事
    std::cout << "虚表第一个函数的地址:[" << (long*)*((long*)(&d)) << "]" << std::endl; // 最左边转成long*的目的是取虚表第一项
    pFun = (Fun)*(long*)*((long*)(&d)); // 虚表里面存的是函数地址，取第0项，则是把Base::f1()的地址拿到，这就是第一个星号的作用
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 1); // 取虚表第二项所指向的函数
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 2);
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 3);
    pFun();
    pFun = (Fun)*((long*)*((long*)(&d)) + 4);
    pFun();
}

int main() {
    testDerivedMultiple();
}