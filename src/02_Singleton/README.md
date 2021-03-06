## c++类的静态成员

当我们把类的成员声明为静态的，那么这意味着无论创建多少个类对象，静态成员都只有一个副本。

静态成员在所有的对象中都是共享的。如果不提供初始化语句，在创建第一个对象的时候，所有的静态数据都会被初始化为零。
我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化。

### 静态成员函数规则
如果把函数成员声明为静态的，*就可以把函数与类的任何特定的对象独立开来*，`静态函数`只要使用类名加上范围解析运算符`::`就可以访问。
静态成员函数只能访问静态成员数据，其他静态成员函数和类外部的其他函数。
静态成员函数有一个类的范围，他们不能访问类的this指针。