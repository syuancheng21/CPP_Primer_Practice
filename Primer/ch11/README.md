# chapter 11 关联容器

## 1. 关联容器类型
- 有序
map set multimap multiset
-  无序
unordered_map unordered_set unordered_multimap unordered_multiset

## 2. pari
- 数据成员是public的，两个成员分别命名为first和second
- map的元素是pair
### 操作
- pair<T1, T2> p;  默认构造值初始化
- pair<T1, T2> p(v1, v2) 用v1和v2来初始化
- make_pair(v1, v2) 返回用v1和v2初始化的pair， 类型由v1和v2的类型推断而来
- p.first 返回p的名为first的公有数据成员
- p.second 返回p的名为second的公有数据成员
- 比较
  - ==， 当first和second成员分别相等时，两个pair相等
- pair对象函数
```
pair<string, int> process(vector<string> &v) {
  if (!v.empty()) {
    return {v.back(), v.back().size()};
  } else {
    return pair<string, int>();
  }
}
```

### 迭代器
- map的value_type是一个pair类型，其中first成员保存const的关键字
  - 我们可以改变pair的值，但是不能改变key
- set中的关键字也是const的，可以用set迭代器来读取元素的值，但不能修改
- 添加元素到map的四种方法(insert) [practice](insert.cpp)
- 删除元素的三种方法(erase) [practice](delete.cpp)
- 访问元素
  - 下标： 如果关键字未在map中， 下标操作会插入一个给定关键字的元素。因此推荐使用find函数
  - count(k) 返回等于k的元素数量，对于不允许重复的容器， 返回值永远是0和1
  - low_bound(k)  迭代器： 第一个关键字>=k
  - upper_bound(k)
  - equal_bound(k)

