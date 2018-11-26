//
// Created by seadream on 2018/10/30.
//

#include "singleton.h"

// 单例 - 懒汉式
Singleton2 *Singleton2::m_pSingleton = NULL;

// 第一次调用才初始化，避免内存浪费。
Singleton2 *Singleton2::GetInstance() {
    if (m_pSingleton == NULL) {
        m_pSingleton = new Singleton2();
    }

    return m_pSingleton;
}

// 单例 - 饿汉式
//Singleton2 * Singleton2::m_pSingleton = new Singleton2();

int main() {
    // 单例 懒汉式

}

