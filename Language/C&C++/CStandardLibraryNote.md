ANSI C标准中有几个标准预定义宏（也是常用的）：

- `__LINE__`：在源代码中插入当前源代码行号；

- `__FILE__`：在源文件中插入当前源文件名（绝对地址）；

  - 改为相对地址的办法

  - ```c
    #define __FILENAME__ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1) : __FILE__)
    ```
    
> 注：
> 1. `char * strrchr(const char*str, char c)`功能是查找字符`c`在字符串`str`中末次出现的位置，并返回这个位置。若未找到，则返回`NULL`。
> 2. `\`一般用作换行，这里要使用转义字符`\\`。

- `__DATE__`：在源文件中插入当前的编译日期

- `__TIME__`：在源文件中插入当前编译时间；

- `__STDC__`：当要求程序严格遵循ANSI C标准时该标识被赋值为1；

- `__cplusplus`：当编写C++程序时该标识符被定义。

编译器在进行源码编译的时候，会自动将这些宏替换为相应内容。



- ASCII（American Standard Code for Information Interchange 美国信息交换标准代码）
- EBCDIC（Extended Binary Coded Decimal Interchange Code 广义二进制编码的十进制交换码）



## errno.h

C 标准库的 **errno.h** 头文件定义了整数变量 **`errno`**，它是通过系统调用设置的，在错误事件中的某些库函数表明了什么发生了错误。该宏扩展为类型为` int `的可更改的左值，因此它可以被一个程序读取和修改。

在程序启动时，**`errno`** 设置为零，C 标准库中的特定函数修改它的值为一些非零值以表示某些类型的错误。您也可以在适当的时候修改它的值或重置为零。

**errno.h** 头文件定义了一系列表示不同错误代码的宏，这些宏应扩展为类型为 **`int`** 的整数常量表达式。

错误代码

| macro    | meaning              |                                                              |
| -------- | -------------------- | ------------------------------------------------------------ |
| `ERANGE` | **Range error**      | 一个变量可以表示的数值范围是有限的，数值过大或者过小都有溢出的风险。例如，pow() 用来求一个数的次方，它的结果极有可能超出浮点类型变量的表示范围；再如，strtod() 用来将字符串转换成浮点数，也有可能会超出范围。在这些情况下，errno 都会被设置为 ERANGE。 |
| `EDOM`   | **Domain error**     | 某些数学函数仅针对一定范围内的数值有意义，我们将这个范围称为域（Domain）。例如，sqrt() 函数仅能对非负数求平方根，如果我们给 sqrt() 传递一个负数，那么 sqrt() 就会将 errno 设置为 EDOM。 |
| `EILSEQ` | **Illegal sequence** | 源自于不合法的字符序列（可以理解为字符串），当使用 mbrtowc()、wcrtomb() 等函数在多字节字符和宽字符之间进行转换时，如果遇到无效的字符，就会将 errno 设置为 EILSEQ。例如`wcrtomb(buffer, L'\xfffff' ,&mbs);`语句中，`L'\xfffff'`就是一个超出范围的宽字符，就是非法字符序列，wcrtomb() 就会将 errno 设置为 EILSEQ。 |

```c
#include <errno.h>
#include <math.h>

	/*...*/

	errno = 0;
	double x;

    /*这里对x进行多步运算*/
	Function(&x);

    /*判断double是否溢出*/
	if(errno == ERANG&&(x == HUGE_VAL || x == -HUGE_VAL))
    {
        /*...*/
    }

    /*...*/
```



## math.h

- `HUGE_VAL`

  > Macro constant that expands to a positive expression of type `double`.
  >
  > A function returns this value when the result of a mathematical operation yields a value that is too large in magnitude to be representable with its return type. This is one of the possible *range errors*, and is signaled by setting [errno](http://www.cplusplus.com/errno) to [ERANGE](http://www.cplusplus.com/ERANGE).
  >
  > Actually, functions may either return a positive or a negative HUGE_VAL (HUGE_VAL or -HUGE_VAL) to indicate the sign of the result.  
  >
  > The same macro constants for type `float` and `long double` are `HUGE_VALF` and `HUGE_VALL`.



