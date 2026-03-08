# Chapter15

## 1.OOP概述
- 一些函数，基类希望派生类可以实现适合自己的版本，这时基类会将这些函数声明为**虚函数**。
- 派生类必须在其内部对基类所有虚函数进行声明, 具体是通过override关键字。
- 使用基类的引用或指针来调用一个虚函数时，将发生**动态绑定**。

## 2.定义基类和派生类
- 基类有两种成员函数
  - 派生类直接继承，不要定义自己的版本
  - 派生类覆盖，定义自己的版本（**虚函数**，virtual关键字）
- protected: 派生类有权访问， 其他用户不能访问，（比如，类实现的对象就不能直接访问）
- 派生类
  - 如果派生类没有覆盖基类的虚函数，则这个虚函数和正常函数一样，派生类直接继承基类的版本。
  - 可以将派生类对象当成基类对象使用。
  - 将基类的指针或引用绑定到派生类对象中的基类部分。
    - 因此，可以将派生类对象或者派生类对象的引用，用在需要基类引用的地方。
    - 也可以将派生类对象的指针，用在需要基类指针的地方。
  - 初始化：
    - 派生类使用基类的构造函数初始化基类部分。
  - 防止继承发生
    - 如果一个类不希望其他类继承它，应该使用**final** `class Base final`
- 类型转换与继承
  - 静态类型: 变量声明的类型； 动态类型: 变量或表达式表示的内存中的对象的类型。
  - 基类指针或引用的静态类型和动态类型很可能不一致。
  - 不能将基类转为派生类。

Pritace:
15.1 What is a virtual member?

A virtual member in a base class expects its derived class define its own version. In particular base classes ordinarily should define a virtual destructor, even if it does no work.

15.2 How does the protected access specifier differ from private?

private member: base class itself and friend can access
protected members: base class itself, friend and derived classes can access

15.9 When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.
[answer](ex15_9.cpp)


## 3.虚函数
- 所有的虚函数都必须有定义，因为编译器也不知道使用哪个虚函数。
- 一个函数被声明为虚函数， 那么在所有派生类中它都是虚函数。
- 派生类虚函数的形参类型要和基类一样。
- final 和 override
  - override 覆盖虚函数
  - final: final函数不能被覆盖
- 还有默认参数的虚函数
  - 使用基类中定义的默认实参，即使实际运行的是派生类中的函数版本

## 4.抽象基类
- 纯虚函数
  - virtual + `=0`
  - 含有纯虚函数的类是**抽象基类**
    - 负责定义**接口**，不能创建一个抽象基类的对象

## 5.访问控制与继承
- protected
  - 基类和派生类的用户对象，不可访问
  - 派生类的成员和友元，可以访问
  - 派生类的成员或友元，只能通过派生类对象来访问基类的pretected成员。

## 6.继承中的类作用域

## 7.构造函数与拷贝控制

## 8.容器与集成

## 9.文本查询程序