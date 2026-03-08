# Chapter3 字符串，向量和数组

3.1 命名空间的using声明
- `using namespace::name`
- 头文件不应包含using声明

3.2 标准库类型string
- 定义和初始化string对象 [string define](./base/string_def.cpp)
- 直接初始化和拷贝初始化
  - 使用`=`等号初始化一个变量，实际上是**拷贝初始化**。
  ```
  string s8 = string(10, 'c');
  equal to
  string temp(10, 'c');
  string s8 = temp;
  ```
- string 对象上的操作 [string operation]()
  - size()返回无符号整形数
- string的比较 slang > phrase > hello
```
string str = "hello";
string phrase = "hello world";
string slang = "hiya";
```
- string 还有一些方法来判断字符
- 操作字符 [char operation](./base/char_operation.cpp)
- 下标运算符 `[]`
  - 参数：string::size_type类型
  - 返回值：该位置上字符的引用


3.3 标准库类型vector
- 定义和初始化vector [](./base/vector_def.cpp)
- vector操作 
  - note： 不能用下标的方式添加元素。`ivec[idx] = value`。

3.4 迭代器

3.5 数组
- 数组的定义和初始化 [array define practice](./base/array_def.cpp)
- 字符数组的特殊性  [char array](./base/char_array.cpp)
- 指针和数组
  - 数组名==指向数组首元素的指针
    - auto 推断一个数组名得到的类型是 指针。
    - decltype仍然推断出数组
  - 指针也是迭代器
    - begin 和 end函数
      - begin: 返回首元素指针
      - end：返回尾元素的下一位置的指针
      - warn：尾后指针不能 解引用和递增
  - 指针运算
    - 加减==前进or后退
    - 两个指针相减的结果是它们之间的距离。（warn：两个指针必须指向同一个数组的元素）
      - 结果是ptrdiff_t类型，是一种带符号类型
  - 允许解引用指针[point pratice](./base/pointer.cpp)

3.6 多维数组
