# Macro

关于C语言的宏编程的一点了解。

> 定义一个宏，求两个数中的最大数

我们来看几种写法，NB程度依次递增。

```c
#define MAX(x,y) x > y ? x : y

#define MAX(x,y) (x) > (y) ? (x) : (y)

#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define MAX(x,y) ({    \
    int _x = x;        \
    int _y = y;        \
    _x > _y ? _x : _y; \
})

#define MAX(type,x,y) ({\
    type _x = x;        \
    type _y = y;        \
    _x > _y ? _x : _y;  \
})

#define max(x, y) ({   \
    typeof(x) _x = (x);\
    typeof(y) _y = (y);\
    (void)(&_x == &_y);\
    _x > _y ? _x : _y; \
})
/*(void)(&_x == &_y)*/
/*
 * 一是用来给用户提示一个警告，对于不同类型的指针比较，编译器会给一个警告，提示两种数据类型不同；二是，当两个值比较，比较的结果没有用到，有些编译器可能会给出一个warning，加个(void)后，就可以消除这个警告
 */
```

> 如果宏里有多过一个语句（statement），就需要用 `do { /*...*/ } while(0)` 包裹成单个语句，否则会有如下的问题：

~~~c
#define M() a(); b()
if (cond)
     M();
 else
    c();
 
 /* 预处理后 */
 
 if (cond)
     a(); b(); /* b(); 在 if 之外     */
 else          /* <- else 缺乏对应 if */
     c();
~~~
>
> 只用 `{ }` 也不行：
>
 ~~~c
 #define M() { a(); b(); }
 
 /* 预处理后 */
 
 if (cond)
     { a(); b(); }; /* 最后的分号代表 if 语句结束 */
 else               /* else 缺乏对应 if */
     c();
 ~~~

> 用 do while 就行了：

 ~~~c
 #define M() do { a(); b(); } while(0)
 
 /* 预处理后 */
 
 if (cond)
     do { a(); b(); } while(0);
 else
     c();
 ~~~
