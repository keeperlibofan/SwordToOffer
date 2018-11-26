//
// Created by seadream on 2018/10/30.
//

#ifndef SWORDTOOFFER_SINGLETON_H
#define SWORDTOOFFER_SINGLETON_H

/**
 * 单例模式仅仅有一个实例
 * 单例类必须自行创建自己唯一的实例
 * 单例类必须给所以其他对象提供这个实例
 *
 * 具体实现
 * 提供一个private构造函数 (防止外部调用构造函数而构造类的实例)
 * 提供一个static private 对象
 * 提供一个static public函数，用于创建或者获取其本身的静态私有对象。（例如：GetInstance）
 *
 * 关键点
 * 线程安全
 * 资源释放
 */

#include <iostream>

 using namespace std;
class Singleton{
public:
    // 将返回的类型应该为指针，这是为了避免编译器调用默认的拷贝函数。 TODO 搞懂它
    static Singleton& GetInstance() {
        static Singleton instance; // 暗中调用构造函数
        return instance;
    }
    void doSomething() {
        cout << "Do something" << endl;
    }

private:
    Singleton() {} // 构造函数 （被保护）
    Singleton(Singleton const&); // 无需实现
    Singleton&operator = (const Singleton&); // 赋值符构造函数，无需实现
};

// 单例 - 懒汉式/饿汉式公用
// 懒汉模式 就是指单例实例在程序运行时被立即初始化
class Singleton2
{
public:
    static Singleton2* GetInstance();

private:
    Singleton2() {}  // 构造函数（被保护）

private:
    static Singleton2 *m_pSingleton;  // 指向单例对象的指针
};

#endif //SWORDTOOFFER_SINGLETON_H
