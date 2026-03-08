# Chapter13 拷贝控制

## 1.拷贝、赋值、销毁
### 拷贝构造函数
- **what**: 如果一个构造函数的第一个形参是**自身类型的引用**，而且其他参数都有默认值，则此构造函数称为**拷贝构造函数**，`class Foo { public: Foo(const Foo&); }`
  - 不能是explicit的，因为拷贝构造函数在几种情况下会被隐式的调用。
    > Note: `explicit`抑制构造函数的隐式转换
  - 即使我们定义了其他构造函数(非拷贝)，编译器也会为我们合成一个拷贝构造函数。
    - 编译器把给定对象中的每个非static的成员拷贝到正在创建的对象中来。
- 拷贝初始化
  - 通常使用拷贝构造函数或者移动构造函数
  - when [practice](ex13_13.h)
    - 用`=`**定义变量**时
    - 将一个对象作为实参传递给一个非引用类型的形参
    - 从一个返回类型是非引用类型的函数中返回一个对象
    - 用花括号列表初始化一个数组中的元素或一个聚合类中的成员
    - insert push是拷贝初始化，emplace是直接初始化
  - 以下共有六处使用了拷贝构造函数
```
Point global;
Point foo_bar(Point arg) // 1
{
	Point local = arg, *heap = new Point(global); // 2: Point local = arg,  3: Point *heap = new Point(global) 
	*heap = local; 
	Point pa[4] = { local, *heap }; // 4, 5
	return *heap;  // 6
}
```
### 拷贝赋值运算符
- `Sales_data trans, accum; trans = accum;` 使用Sales_data的拷贝复制运算符。
- `operator=`函数，左侧对象绑定到this参数， 右侧运算对象作为显式参数传递。
  - 可被重载
- `Foo& operator=(const Foo&);`
- 合成拷贝复制运算符：如果一个类未定义自己的拷贝复制运算符，编译器会生成一个。

### 析构函数
- `~Foo(){}`，没有返回值，也不接受参数。
  - 执行过程
    - 1.执行函数体
    - 2.析构成员
      - 成员按照逆序销毁
  - 析构函数自身并不直接销毁成员。成员是在析构函数体之后隐含的析构阶段被销毁的。
- When
  - 变量离开其作用域时
  - 当一个对象被销毁时，其成员被销毁
    - 对于普通指针， 不会delete它所指的对象
  - 容器被销毁时，其元素被销毁
  - 指针 //TODO
  - 对于临时对象，当创建它的完整表达式结束时被销毁
```
bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
// accum, item1 and item2 会发生析构
```
- 合成析构函数
  - 一个类未定义自己的析构函数时，编译器会为它定义一个**合成析构函数**

### 三/五法则
- 需要析构函数的类也需要拷贝构造函数和拷贝赋值运算符
- 需要拷贝构造函数的类也需要拷贝赋值运算符

### 使用=default
- 可以将拷贝控制成员定义为`=default`来显示地要求编译器生成合成的版本。
- 当我们在类内用`=default`修饰成员函数，合成的函数将隐式地声明为inline的。
  - 如果不希望是inline，应该在类外定义的时候用`=default`
### 阻止拷贝
- `=delete`加在函数声明时的参数列表后面可以将函数定义为删除的。
  - 必须出现在函数第一次声明的时候。
  - 析构函数不能删除。
- 合成删除的拷贝控制成员
  - 如果一个类有数据成员不能默认构造、拷贝、赋值或销毁，则对应的成员函数将被定义为删除的。

## 2.拷贝控制和资源管理
- 值：  副本和原对象**是完全独立**。如：标准容器库、string
- 指针：副本和原对象**使用相同的底层数据**。如：shared_ptr
- 非值非指针：unique_ptr(不允许拷贝或复制)
### 行为像值的类
[练习 13.22](ex13_22.h)
- 拷贝赋值运算符
  - 将对象赋予它自身，必须能正常工作.(销毁左侧运算对象资源之前，拷贝右侧运算对象)
  - 组合了析构函数和拷贝构造函数的工作
### 行为像指针的类
[练习 13.27](ex13_27.h)
- 引用计数法
## 3.交换操作
- swap
  - 在需要交换两个元素时会调用swap
  - swap函数应该调用swap，而不是std::swap
    - 如果一个类成员有自己的swap函数，那调用std::swap就是错误的
  - Would the pointerlike version of HasPtr benefit from defining a swap function? If so, what is the benefit? If not, why not?
    > Essentially, the specific avoiding memory allocation is the reason why it improve performance. As for the pointerlike version, no dynamic memory allocation anyway. Thus, a specific version for it will not improve the performance.

## 4.拷贝控制示例
[practice](ex13_34_36_37.h)

## 5.动态内存管理类
### allocator 
#### 分配/释放内存(未构造)
```
allocator<string> alloc;
auto const p = alloc.allocate(n); //分配一段原始的，未构造的内存，保存n个string
alloc.deallocate(p, n); //释放内存，释放从指针p开始的内存， 这块内存保存了n个string
```
#### 构造/销毁对象
```
auto q = p;
alloc.construct(q++); //*q为空字符串
alloc.construct(q++, 3, 'c');// *q为 ccc
alloc.construct(q++, "hi");//*q未hi

alloc.destroy(p); //p为指针，对p指向的对象执行析构函数
```

#### 拷贝和填充未初始化内存
```
uninitialized_copy(b,e,b2);//从迭代器b和e指出的返回中拷贝元素到迭代器b2指定的未构造的原始内存中。

//e.g
//扩容为原来的两倍
auto p = alloc.allocate(vi.size() * 2);
//将原来的元素拷贝到从p开始的新的内存
auto q = uninitialed_copy(vi.begin(), vi.end(), p);
//
uninitialed_fill_n(q,vi.size(), 42); //剩余元素初始化为42
```



## 6.对象移动
### 右值引用
#### 左值引用和右值引用的区别 （练习13.45）
左值引用和右值引用是C++中两种不同类型的引用，它们在语义上和用法上有一些重要区别：
##### 什么是右值和左值？
左值（lvalue）: 可以取地址的值。简单地说，左值是一个有名字并且可以在表达式的生命周期内访问的对象。比如变量、数组元素等。
```
int x = 10;     // x是一个左值
int* p = &x;    // 可以取x的地址
```
右值（rvalue）: 不能取地址的临时值。右值是一个没有名字，并且只在表达式求值期间存在的对象，比如字面量、临时对象、表达式的返回值等。
```
int y = 10;     // 10是一个右值
int z = x + y;  // x + y 的结果是一个右值
```

##### 定义
左值引用（lvalue reference）是通过 & 符号定义的，用于引用左值。
右值引用（rvalue reference）是通过 && 符号定义的，用于引用右值。
##### 绑定对象
左值引用只能绑定到左值(具名对象).
右值引用只能绑定到右值(临时对象、字面常量、即将被销毁的对象).
##### 生命周期
左值引用的生命周期通常与其绑定的对象相同。
右值引用通常用于表示临时对象或者即将被销毁的对象，因此其生命周期可能较短。
##### 用途
左值引用通常用于传递参数、函数返回值以及引用类型的成员变量。
右值引用通常用于移动语义、完美转发以及某些高级模板编程技术。

Important：
- 以左值为参数时调用拷贝构造/赋值，以右值为参数时调用移动构造/赋值
  - 以左值引用为参数的构造函数/赋值重载称为拷贝构造/赋值，以右值引用为参数的构造函数/赋值重载称为移动构造/赋值。
- 右值引用是左值
  - 变量是左值， 因此不能将一个右值引用直接绑定到一个变量上， 即使这个变量是右值引用也不行。
  ```
  int &&rr1 = 42;
  int &&rr2 = rr1; //错误： 表达式rr1是左值。
  ```

示例：
```
void foo(int& lref) {
    std::cout << "Received a left value reference" << std::endl;
}

void bar(int&& rref) {
    std::cout << "Received a right value reference" << std::endl;
}

int main() {
    int x = 5;  // x 是左值
    int&& y = 10;  // 10 是右值
    int& z = x;  // x 是左值

    foo(x);  // 传递左值给 foo 函数
    // foo(y);  // 错误！y 是右值，不能绑定到左值引用
    bar(std::move(y));  // 使用 std::move 将 y 转换为右值引用，传递给 bar 函数

    return 0;
}
```
#### move函数
用来获得绑定到左值上的右值引用。
调用move方法意味着承诺： 除了对rr1赋值或销毁它之外，我们将不再使用它。
```
  int &&rr1 = 42;
  int &&rr2 = rr1; //错误：rr1是左值
  int &&rr3 = std::move(rr1);
```
### 移动构造函数与移动赋值运算符
#### 特点
- 从给定对象“窃取”资源，而不是拷贝资源。
- 第一个参数是改类类型的一个右值引用，与拷贝构造一样， 任何额外的参数都必须有默认实参。
- 移后源对象：销毁它是无害的。 必须不再指向被移动的资源，这些资源的所有权已经归于新创建的对象。
- How to move?
  - 不分配任何新内存，接管给定的对象中的内存。
  - 接管后将给定对象中的指针都置为nullptr，这样完成移动操作。
- 移后源对象必须可析构


#### noexcept
- 是我们承诺一个函数不抛出异常的一种方法。


### 右值引用和成员函数(提供拷贝和移动版本的成员函数)
- 拷贝： const左值引用
- 移动： 非const的右值引用
```
void push_back(const X&);//拷贝
void push_back(X&&);//移动
```

#### 引用限定符
- 为了避免这种操作`s1 + s2 = "!wow";`--右值赋值。我们需要强制左侧运算对象是一个左值。
- 引用限定符
```
Foo &operator=(const Foo&) &;//只能向可修改的左值赋值。

Foo retVal();
Foo &retFoo();
Foo i,j;
retFoo() = i;//正确：retFoo()返回一个左值。
retVal() = j;//错误， retVal()返回一个右值。
```
- 如果一个成员函数有引用限定符， 那么它的其他重载函数也必须要有引用限定符。