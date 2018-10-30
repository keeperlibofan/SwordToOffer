//
// Created by seadream on 2018/10/30.
//

#ifndef SWORDTOOFFER_CMYSTRING_H
#define SWORDTOOFFER_CMYSTRING_H


#include <cstring>

class CMyString {
public:
    CMyString(const char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString&operator = (const CMyString& str) { // 相当于把str赋值给这个新的函数
        if (this != &str) {
            CMyString tempStr(str);

            char *tempPtr = tempStr.m_pData; // 为什么可以引用到内部的private变量
            tempStr.m_pData = str.m_pData;      // 当运行出if作用域就会被调用析构函数释放
            m_pData = tempPtr;
        }

        return *this;
    };
private:
    char *m_pData;
};

// 一般构造函数
CMyString::CMyString(const char *pData) {
    if (pData == nullptr) {
        m_pData = new char[1];
        m_pData[0] = '\0';
    } else {
        m_pData = new char[strlen(pData)+1];
        strcpy(m_pData, pData);
    }
}

//拷贝构造函数
CMyString::CMyString(const CMyString &str) {
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

// 析构函数
CMyString::~CMyString(void) {
    delete []m_pData;
}

#endif //SWORDTOOFFER_CMYSTRING_H
