# C&C++——Long ago

- `NaN`：阶码的每个二进制位全为1并且尾数不为0；
  无穷：阶码的每个二进制位全为1并且尾数为0；符号位为0，是正无穷，符号位为1是负无穷。
  所以`NaN`、正无穷、负无穷可以如此定义，可以如此判断是否`NaN`。
```c++
  //float
  int __NaN=0xFFC00000;
  int __Infinity=0x7F800000;
  int __Neg_Infinity=0xFF800000;
  const float NaN=*((float *)&__NaN);
  const float Infinity=*((float *)&__Infinity);
  const float Neg_Infinity=*((float *)&__Neg_Infinity); 

  bool IsNaN(float dat)
  {
   int & ref=*(int *)&dat;
   return (ref&0x7F800000) == 0x7F800000 && (ref&0x7FFFFF)!=0;
  }

  //double
  int64_t __NaN=0xFFF8000000000000;
  int64_t __Infinity=0x7FF0000000000000;
  int64_t __Neg_Infinity=0xFFF0000000000000;
  const double NaN=*((double *)&__NaN);
  const double Infinity=*((double *)&__Infinity);
  const double Neg_Infinity=*((double *)&__Neg_Infinity); 

  bool IsNaN(double dat)
  {
   int64_t & ref=*(__int64 *)&dat;
   return (ref&0x7FF0000000000000) == 0x7FF0000000000000 && (ref&0xfffffffffffff)!=0;
  }
```

- 以上的设置方法就纯粹是作为一个界，但很多时候我们需要对无穷做一些运算，比如$\infty + \infty = \infty $，用上面的“界”会导致严重的溢出，因此我们需要一个替代品，即`0x3F3F3F3F`，他的十进制是$1061109567$，即$10^9$量级，一般场合下的数据都是小于$10^9$的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。由于一般的数据都不会大于$10^9$，所以当我们把无穷大加上一个数据时，它并不会溢出（这就满足了$\infty +K=\infty $），事实上`0x3f3f3f3f+0x3f3f3f3f=2122219134`，这非常大但却没有超过`32_bit int`的表示范围，所以`0x3f3f3f3f`还满足了我们$\infty + \infty = \infty $的需求。

- 所谓字典序，就是字符串在字典中的顺序。一般地，对于两个字符串，从第一个字符开始比较，当某一个位置的字符不同时，该位置字符较小的串，字典序较小（例如，$abc$比$bcd$小）；如果其中一个字符串已经没有更多字符，但另一个字符串还没结束，则较短的字符串的字典序较小（例如，$hi$比$history$小）。字典序的概念可以推广到任意序列，例如，序列$1, 2, 4, 7$比$1, 2, 5$小。

- 对typedef的理解

  ```c++
  typedef char* pstring;
  const pstring cstr1 = "Hello World";//cstr1是指向char的常量指针
  const char* cstr2 = "Hello World";//cstr2是指向char型常量的指针
  const pstring *ps;//指向指向char的常量指针
  ```

  第二行和第三行是不同的，因为`const`是对给定类型的修饰，`typedef`定义的类型别名算是一个整体。
  
- 一种合理的注释建议：对于较长的`while`在末尾花括号后注释`//while`。

- 在使用的头文件后标注该文件所用到的函数。

- 在 C 语言中，数组长度、索引值最好使用 `size_t` 类型，而不是 `int` 或 `unsigned`。

- 在结构体中，如果两个元素存在互斥关系则可使用`union`。

  如一个值不可能同时为数字和字符串则可以有

  ```c
  typedef struct {
      char* s;
      size_t len;
      double n;
      lept_type type;
  }lept_value;
  
  typedef struct {
      union {
          struct { char* s; size_t len; }s;  /* string */
          double n;                          /* number */
      }u;
      lept_type type;
  }lept_value;
  ```


- 如果一个文本文件是如下内容的

```
//test.txt
12,123,21312
```

可以直接使用`include`

```c
int a[] = {
#include "test.txt"
}
```

就会直接生成一个数组。

## 6.13

### 范围for循环

C++11新标准，范围for循环，如下实例，遍历多维数组

```C++
int array[10][10];
for(const auto &row : array)//外层
	for(auto col : row)//内层
		cout << col << endl;
```

注意到对外层循环的时候要用引用，这样`row`才是一维数组，而不是`int*`，如下的写法是错误的

```c++
for(auto row : array)
	for(auto col : row)
		cout << col << endl;
```

因为这里`row`的类型是`int*`，一个指针是不可以被遍历的。

当你需要修改数组内部的值时所有的`for`循环内部都要使用引用

```c++
for(auto &row : array)
	for(auto &col : row)
		cout << col << endl;
```

## 6.15

### c++的异常处理机制

- `throw`表达式

  - `throw expression;`
  - 表达式的类型就是抛出的异常类型
  - 抛出异常将终止当前函数，并把控制权移交给能处理该异常的代码。

- try`语句块

  - ```c++
    try{
    	//program statements;
    }catch(exception1){
    	//handler statements;
    }catch(exception2){
    	//handler statements;
    }//...
    ```

  - `try`块中声明的的变量的作用域只在`try`的块中。



- | 标准异常类         | 描述                                                   | 头文件      |
  | ------------------ | ------------------------------------------------------ | ----------- |
  | `exception`        | 最通用的异常类，只报告异常的发生而不提供任何额外的信息 | `exception` |
  | `runtime_error`    | 只有在运行时才能检测出的错误                           | `stdexcept` |
  | `rang_error`       | 运行时错误：产生了超出有意义值域范围的结果             | `stdexcept` |
  | `overflow_error`   | 运行时错误：计算上溢                                   | `stdexcept` |
  | `underflow_error`  | 运行时错误：计算下溢                                   | `stdexcept` |
  | `logic_error`      | 程序逻辑错误                                           | `stdexcept` |
  | `domain_error`     | 逻辑错误：参数对应的结果值不存在                       | `stdexcept` |
  | `invalid_argument` | 逻辑错误：无效参数                                     | `stdexcept` |
  | `length_error`     | 逻辑错误：试图创建一个超出该类型最大长度的对象         | `stdexcept` |
  | `out_of_range`     | 逻辑错误：使用一个超出有效范围的值                     | `stdexcept` |
  | `bad_alloc`        | 内存动态分配错误                                       | `new`       |
  | `bad_cast`         | dynamic_cast类型转换出错                               | `type_info` |

- 当异常被抛出时，首先搜索抛出的该异常的函数。如果没有找到匹配的`catch`子句，终止该函数，并在调用该函数的函数中继续寻找，如果没有找到匹配的`catch`子句，则终止这个新的函数，以此类推，沿着程序的执行路径逐层回退，直到找到合适类型的`catch`子句为止。如果找不到，则进入标准库函数`terminate`。该函数域系统有关，一般情况下，该执行函数将导致程序非正常退出。如果没`try`语句块同时抛出异常，则同样按该标准库函数处理。

## 6.17

### 尾置返回类型

尾置返回类型(trailing return type)是C++11中新增的特性，任何函数的定义都可以使用尾置返回类型，但是尾置返回类型更适合用于返回类型比较复杂的场景，如返回一个数组指针。

```C++
/*正常写法*/
int (*func(int i))[10]
/*尾置写法*/
auto func(int i)->int (*)[10]
```

## 7.11

### 顺序容器

#### 使用原则（建议）

1. 没有更好用的就用`vector`。
2. 有很多小元素，注重空间额外开销，常用`list`或`forward_list`。
3. 随机访问`vector`或`deque`。
4. 中间插入`list`或`forward_list`。
5. 头尾插入`deque`。

## 8.16

### vector

#### 初始化

```c++
vector<T> v1;						//空vector,仅定义了元素类型
vector<T> v2(v1);					//复制v1
vector<T> v3(n);					//声明了一个具有n个元素的vector,其中所有值均为空对象
vector<T> v4(n, m);					//声明了一个具有n个元素的vector,其中所有值均为m
vector<T> v5{T1, T2, T3};			//声明了一个包含列表内所有元素的vector,大小为列表元素个数
vector<T> v6 = v5;					//等价于v2
vector<T> v7 = {T1, T2, T3};		//等价于v5
vector<T> v8(v5.begin(), v5.end())	//取两个迭代器间(左闭右开,即[begin,end))的元素
```

#### 常用操作

| 赋值     |      |
| -------- | ---- |
| `assign` | 赋值 |

**注：**

1. `assign`也是可以有以上初始化`v4`和`v8`的方式来赋值。
2. `assign`释放了原来的数据空间，并分配了新的数据空间。

| 访问         |                                    |
| ------------ | ---------------------------------- |
| `at`         | 访问指定元素，同时进行越界检查     |
| `operator[]` | 访问指定元素                       |
| `front`      | 访问第一个元素                     |
| `back`       | 访问最后一个元素                   |
| `data`       | 返回指向内存中数组第一个元素的指针 |

**注：**

1. 当访问越界时，下标`[]`赋值会显示`SIGSEGV`段错误。

   `at`赋值会显示`terminate called after throwing an instance of 'std::out of range'`。

   c++标准不要求`vector::operator[]`进行下标越界检查，原因是为了效率，总是强制下标越界检查会增加程序的性能开销。

   因此最好不要这样赋值，`push_back`比较安全。

2. `data`会返回一个指针，因为vector里面的元素都是顺序连续存放的，该指针可以通过偏移量来访问数组内的所有元素。

| 迭代器             |                              |
| ------------------ | ---------------------------- |
| `begin` `cbegin`   | 返回指向第一个元素的迭代器   |
| `end` `cend`       | 返回容器尾端的迭代器         |
| `rbegin` `crbegin` | 返回最后一个元素的逆向迭代器 |
| `rend` `crend`     | 返回容器前端的逆向迭代器     |

**注：**

1. `r`指reverse，`c`指constant。
2. `end() - 1 == rbegin()` `begin() == rend() + 1`

| 容量            |                                      |
| --------------- | ------------------------------------ |
| `empty`         | 检查容器是否为空                     |
| `size`          | 返回已经容纳的元素数                 |
| `max_size`      | 返回可容纳的最大元素数               |
| `reserve`       | 预留存储空间                         |
| `capacity`      | 返回当前存储空间能够容纳的元素数     |
| `shrink_to_fit` | 通过释放未使用的内存以减少内存的使用 |

**注：**

1. 此值通常反映容器大小上的理论极限，至多为 `std::numeric_limits<difference_type>::max() `。运行时，可用 RAM 总量可能会限制容器大小到小于 `max_size()` 的值。
2. `capacity`做的事是将预留空间也算上，计算当前的空间里总共可以存储多少元素。当重新预留的空间小于原空间时，将不会做任何事。
3. `reserve`的参数一定要大于当前`capacity`否则不会做任何事。
4. `shrink_to_fit`是c++11里面的，其释放预留空间，使得`capacity() == size()`。

| 修改器         |                            |
| -------------- | -------------------------- |
| `clear`        | 清空容器                   |
| `insert`       | 插入元素                   |
| `emplace`      | 原位构造元素               |
| `erase`        | 擦除元素                   |
| `push_back`    | 将元素添加至容器末尾       |
| `emplace_back` | 在容器末尾就地构造元素     |
| `pop_back`     | 移除最后一个元素           |
| `resize`       | 改变容器中可存储的元素个数 |
| `swap`         | 交换元素                   |

**注：**

1. `clear`仅删除了内存中的元素，使得`size`为`0`，但`capacity`不变。

2. ```c++
   v.insert(it, m);				//在迭代器it前插入元素m
   v.insert(it, n, m);				//在迭代器it前插入n个元素m
   v.insert(it, begin, end);	//在迭代器it前插入区间[begin, end)中的元素
   ```

3. `resize`函数可以有两个参数，第一个参数是容器新的大小， 第二个参数是要加入容器中的新元素，如果这个参数被省略，那么就调用元素对象的默认构造函数。`resize`改变了`vector`的`capacity`同时也增加了它的`size`。

4. `swap`是和别的`vector`交换，交换之后，尾后迭代器将非法。

5. ```c++
   v.erase(it);		//擦除迭代器it处的元素
   v.erase(begin, end);//擦除区间[begin, end)间的元素
   ```

6. 一定要注意，对于以上操作之后或多或少部分甚至全部的迭代器和引用将无效，注意重新赋值。