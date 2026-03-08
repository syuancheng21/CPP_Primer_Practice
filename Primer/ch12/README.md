# Chapter12 动态内存
- 分配在静态或栈内存中的对象由**编译器自动创建和销毁**。
  - 栈对象仅在其定义的程序块运行时才存在。
  - static对象在使用之前分配，在程序结束时销毁。
- 内存池：堆(heap)
  - 存储动态分配的对象（**动态对象**：程序运行时分配的对象）

## 动态内存与智能指针
- 动态内存管理`new + delete`
  - new: 分配空间，并返回一个指向该对象的指针。
  - delete: 接受一个动态对象的指针，销毁该对象，并释放与之关联的内存。
  - 没有delete会内存泄露，delete了还有引用的对象会导致非法内存指针。
- 智能指针`shared_ptr unique_ptr weak_ptr`
  - shared_ptr: 允许多个指针指向同一个对象
  - unique_ptr: 独占所指向的对象
  - weak_ptr: 指向shared_ptr所管理的对象

### shared_ptr类
- 支持的操作
  - `shared_ptr<T> sp`:空智能指针，可以指向类型为T的对象
  - `if(p)`将p作为一个条件判断，若指向一个对象，则为true
  - `*p`解引用，获得它指向的对象
  - `p->mem` <=>  `(*p).mem`
  - `p->get()` 返回p中保存的指针
  - `swap(p, q); p.swap(q);` 交换p和q中保存的指针
  - `make_shared<T>(args)` 返回一个shared_ptr，指向动态分配的对象，其类型为T，使用args来初始化的。
    - 创建的参数必须与T的某个构造函数相匹配。
  - `shared_ptr<T>p(q)`: p是shared_ptr q的拷贝；会使q中的计数器增加。
  - `p=q`p和q都是shared_ptr，递减p的引用计数，增加q的引用计数。
- shared_ptr的拷贝和赋值
  - 在进行拷贝或赋值的时候，**每个**shared_ptr都会记录有多少个其他shared_ptr指向**相同**的对象。
    -  引用计数增加
       -  使用一个shared_ptr初始化另一个shared_ptr
       -  将shared_ptr作为参数传给一个函数
       -  作为函数的返回值
    - 引用计数递减
      - 当给一个shared_ptr赋予新值
      - shared_ptr被销毁；局部的shared_ptr离开作用域
    - 一旦计数器变为0，就会自动释放自己管理的对象
- shared_ptr自动销毁所管理的对象
  - shared_ptr的析构函数会递减它所指向的对象的引用计数，如果引用计数变为0，shared_ptr的析构函数就会销毁对象，并释放占用的内存
- shared_ptr如果被存放在容器中，而后不再需要全部元素，只是使用其中一部分，那么需要手动erase不需要的元素。
- 程序使用动态内存的原因：
  - 1. 程序不知道自己需要多少对象；容器类
  - 2. 程序不知道所需对象的准确类型
  - 3. 程序需要在多个对象间共享数据

### 直接管理内存
- new动态分类和初始化对象
  - 在堆(自由空间)分配的内存是**无名**的，因此new无法为分配的对象**命名**，而是返回一个**指向该对象的指针**。
- 动态分配const对象
  - `const string *pos = new const string`
  - 地址不可变，指向值可变
  - `delete pos` 可以被销毁
- delete
  - 包含两个操作：1.销毁给定的指针所指的对象；2.释放对应的内存。
  - const对象也可以销毁
  - delete之后指针就变为空指针(指向无效的内存)
    - delete之后重置指针，只对当前指针有效

### shared_ptr和new的结合使用
- 使用`new`返回的指针初始化shared_ptr
  - raw指针不能隐式转换为一个shared_ptr，因为接受一个raw指针的shared_ptr的构造函数是explicit的
  - `shared_ptr<int> p1 = new int(10);` 错误
  - `shared_ptr<int> p2(new int(10));` 正确，使用了直接初始化形式
- 不要混合使用raw指针和智能指针, 会导致double free. [Exercise 12.13](../ch12/ex12_13.cpp)
- get() 返回一个raw指针
  - 不要使用get初始化另一个智能指针
- `p.reset(q)` p指向一个新对象. 
- `p.reset(q, d)` 如果p是唯一指向这个对象的，那么会调用d来释放对象。
- `shared_ptr<T> p(q, d)` p接管内置指针q的所有权，并且用d代替delete [Exercise 12.14](../ch12/ex12_14.cpp)
- `shared_ptr<T> p(p2, d)` p是shared_ptr p2的拷贝，并且使用d代替delete


### unique_ptr
- 某一时刻只能有一个unique_ptr指向一个对象。
- 当unique_ptr被销毁时，所指向的对象也被销毁。
- 初始化
  - 初始化时必须绑定到一个new返回的指针
  - 必须直接初始化
  - `unique_ptr<int> p2(new int(42))`
- 不支持普通拷贝和赋值
  - `p3 = p2; unique_ptr<int> p2(p1)` ❎
  - 从函数中返回一个unique_ptr是支持的
- 操作
  - 创建
    - `unique_ptr<T> u1`: 空unique_ptr， 指向T类型的对象
    - `unique_ptr<T, D> u2`: 使用D类型的func来释放对象
    - `unique_ptr<T, D> u(d)`: 空unique_ptr，使用D类型的func来释放对象
  - 解除绑定
    - `u.release()`: u放弃对指针的控制，并返回这个指针，u会被置空.
      - 用来初始化另一个智能指针，或者给另一个智能指针赋值
  - 释放
    - `u.reset()`:释放u指向的对象
    - `u.reset(q)`:令u指向q,原来指向的对象将被释放
    - `u=nullptr`:释放u指向的对象，将u置为空