# chapter 9 顺序容器

## 1 顺序容器概述
- vector
- deque
- list
- forward_list
- array
- string

## 2 容器概览
### 类型别名
- iterator
- const_iterator
- size_type
- difference_type
- value_type
- reference
- const_reference
### 构造函数
- C c; 默认构造函数， 构造空容器。
- C c1(c2); 构造c2的拷贝c1
- C c1=c2; 相同的容器类型，且保存的是相同的元素类型
- C c(b, e); 构造c，将迭代器b和e指定的范围内的元素拷贝到c(array不支持)
- C c{a, b, c...};列表初始化c
- C c(n) c包含n个元素
- C c(n, t) c包含n个初始值为t的元素
### 赋值与swap
- c1 = c2  将c1中的元素替换为c2中的元素。
- c1 = {a, b, c...} 将c1中的元素替换为列表中的元素(array不支持)
- a.swap(b) 交换a与b中元素
  - a和b必须具有相同的类型，swap通常比从c2向c1拷贝元素快的多。
  - 指向容器的迭代器，引用和指针在swap之后， 仍然指向之前所指向的元素。但是swap之后， 这些元素已经属于不同的容器了。
- swap(a, b) 等于与上一个
### 大小
- c.size() c中元素的个数(不支持forward_list)
- c.max_size() c可保存的最大元素数目
- c.empty() 
### 添加和删除元素
- c.insert(args) 将args中的元素拷贝进c
- c.emplace(inits) 使用inits构造c中的一个元素
- c.earse(args) 删除指定的元素
- c.clear() 删除c的所有元素，返回void

### 关系运算符
- == != 
- <, <=, >, >=
### 获取迭代器
- c.begin(), c.end() 返回指向c首元素和尾元素之后位置的迭代器
- c.cbegin(), c.cend() 返回const_interator

## 3 顺序容器操作
### 添加元素
- c.insert(p,t) 
- c.emplace(p,args) 在迭代器p指向的元素之前， 创建一个由t或者args创建的元素，返回指向新添加元素的迭代器
- push vs emplace
  - push: 元素类型的对象， 拷贝到容器中
  - emplace： 将参数传递给元素类型的构造函数
### 访问元素
- at和下标操作： 只适用于string，vector， deque和array，返回该元素的引用
- c.back() 返回c中尾元素的引用
- c.front() 返回c中首元素的引用
### 删除元素
- c.pop_back() 删除c中尾元素，返回void
- c.pop_front() 删除c中首元素，返回void
- c.erase(p) 删除迭代器p所指定的元素，返回被删除元素之后的迭代器
- c.erase(b,e) 删除b和e所指定范围内的元素，返回最后一个被删元素之后元素的迭代器 **左闭右开**
- c.clear() 删除所有元素
### 操作导致迭代器失效
> 指针， 引用或迭代器是指向容器中的元素的。因此对容器的操作， 可能会导致它们指向的元素不存在。
- 添加元素后，且存储空间被重新分配。则迭代器、指针和引用都会失效。
  - 未重新分配，插入位置之前有效，之后失效
- 删除元素，指向被删除元素之前元素的迭代器、指针和引用有效。
> 不要保存end返回的迭代器。当添加或者删除元素后， vector string的尾后迭代器总会失效。
> 因此， 必须在每次插入操作后重新调用end方法。


## 4 vector对象是如何增长的
### 操作
- c.capacity() 不重新分配内存空间的话， c可以保存多少元素
- c.reserve(n) 分配至少能容纳n个元素的内存空间
- c.shrink_to_fit() 请将capacity减少为与size相同大小
- c.resize() 是减少容器中元素数目

## 5 额外的string操作
### 构造
- string s(cp, n) s是cp指向的数组中前n个字符的拷贝。
- string s(s2, pos2) s是string s2从下标pos2开始的字符的拷贝
- string s(s2, pos2, len2) s是string s2从下表pos2开始len2个字符的拷贝
- 构造函数接受一个string或者const char*参数
### 子字符串操作
- s.substr(pos, n) 返回一个子字符串， 包含s从pos开始的n个字符的拷贝
### 改变string的其他方法
- s.insert(pos, args) 在pos之前插入args指定字符， pos是下标或者迭代器
- s.erase(pos, len) 删除从位置pos开始的len个字符，如果len省略，则直到末尾
- s.assign(args) 将s中的字符替换为args指定的字符
- s.append(args) 将args追加到s，返回一个指向s的引用
- s.replace(range, args) 删除s中范围range内的字符，替换为args指定的字符


## 6 容器适配器
