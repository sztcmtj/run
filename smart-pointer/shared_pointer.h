#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

#include <iostream>

template <class T>
class SharedPointer {
public:
    // Constructor
    SharedPointer(T* p) : m_p(p) {
        std::cout << "进入构造函数" << std::endl;
        if (m_count == NULL) {
            m_count = new int(1);
        }
        std::cout << "退出构造函数" << std::endl;
    }

    SharedPointer() : m_p(NULL), m_count(NULL) {
        std::cout << "进入默认构造函数" << std::endl;
        std::cout << "退出默认构造函数" << std::endl;
    }
    
    // Deconstructor
    ~SharedPointer() {
        std::cout << "进入析构函数" << std::endl;
        if (m_count != NULL && --(*m_count) <= 0) {
            if (m_p != NULL) {
                delete m_p;
            }
            
            if (m_count != NULL) {
                delete m_count;
            }
            m_p = NULL;
            m_count = NULL;
        }
        std::cout << "退出析构函数" << std::endl;
    }

    // Copy Constructor
    SharedPointer(const SharedPointer& sp) : m_p(sp.m_p), m_count(sp.m_count) {
        std::cout << "进入拷贝构造函数" << std::endl;
        if (m_count) {
            (*m_count)++;
        }
        std::cout << "退出拷贝构造函数" << std::endl;
    }

    // Assign Constructor
    SharedPointer<T>& operator=(SharedPointer<T>& rhs) {
        std::cout << "进入赋值构造函数" << std::endl;
        if (rhs == *this) {
            return *this;
        }

        // Release original pointer
        release();
        m_p = rhs.m_p;
        m_count = rhs.m_count;
        if (m_count != NULL) {
            (*m_count)++;
        }
        std::cout << "退出赋值构造函数" << std::endl; 
        return *this;
    }

    bool operator==(SharedPointer& rhs) {
        return m_p == rhs.m_p;
    }

    T* get() {
        return m_p;
    }

    int use_count() {
        if (m_count) {
            return *m_count;
        }
        return 0;
    }

    void release() {
        std::cout << "release 现有对象" << std::endl;
        if (m_count != NULL && (--(*m_count) <= 0)) {
            // 若引用计数为0释放持有对象
            delete m_count;
            m_count == NULL;
            delete m_p;
            m_p = NULL;
            std::cout << "release 引用计数为0,释放对象" << std::endl;
            return;
        }

        // 释放本智能指针，但不释放原持有的对象
        m_count = NULL;
        m_p = NULL;
        std::cout << "release 不释放对象" << std::endl;
    }

private:
    // 实际裸指针
    T* m_p = NULL;
    // 引用计数
    int* m_count = NULL;
};

#endif // __SHARED_POINTER_H__