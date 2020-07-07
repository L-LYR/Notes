### Exercises 1.1-1

----

Give a real-world example in which one of the following computational problems appears: sorting, determining the best order for multiplying matrices, or finding the convex hull.

> 排序：电商推荐系统
>
> 凸壳：模式识别，图象处理

### Exercises 1.1-2

----

Other than speed, what other measures of efficiency might one use in a real-world setting?

> 资源占用，如内存占用，GPU占用等

Exercises 1.1-3

---

Select a data structure that you have seen previously, and discuss its strengths and limitations.

> 静态数组
>
> 优点：随机存取，速度快
>
> 缺点：无法实时扩展大小，插入操作效率不高

### Exercises 1.1-4

---

How are the shortest-path and traveling-salesman problems given above similar? How are they different?

> 相同之处：都是寻找一条代价最小的路径
>
> 不同之处：
>
> 1. 前者是寻找两节点之间的路径，后者是寻找不重复连接所有节点之间的回路，是一个全排列问题。
> 2. 前者是多项式时间即可解决的问题，后者是NP-Complete问题。

### Exercises 1.1-5

---

Come up with a real-world problem in which only the best solution will do. Then come up with one in which a solution that is "approximately" the best is good enough.

> 背包问题，有最优解为什么不用呢？（偏题警告
>
> 车辆调度问题，可行解的代价和理论最优解之间的差距在一定范围内时也可以实行。

### Exercises 1.2-1
---
Give an example of an application that requires algorithmic content at the application level, and discuss the function of the algorithms involved.

> 导航，指纹解锁，人工智能

### Exercises 1.2-2
---
Suppose we are comparing implementations of insertion sort and merge sort on the same machine. For inputs of size n, insertion sort runs in $8n^2$ steps, while merge sort runs in $64n\lg n$steps. For which values of n does insertion sort beat merge sort?

> $8n^2< 64n\lg n\Rightarrow n\le 6$

### Exercises 1.2-3

----
What is the smallest value of n such that an algorithm whose running time is $100n^2$ runs faster than an algorithm whose running time is $2^n$ on the same machine?

> $100n^2>2^n\Rightarrow n\ge 15$

### Problems 1-1: Comparison of running times
---
For each function f(n) and time t in the following table, determine the largest size n of a problem that can be solved in time t, assuming that the algorithm to solve the problem takes f(n) microseconds.

|    Item     |   1 second   |    1 minute    |     1 hour     |      1 day       |      1 month      |       1 year        |         1 century         |
| :---------: | :----------: | :------------: | :------------: | :--------------: | :---------------: | :-----------------: | :-----------------------: |
|  $\lg{n}$   | $2^{{10^6}}$ | $2^{6*{10^7}}$ | $2^{36*10^8}$  |  $2^{864*10^8}$  | $2^{25920*10^8}$  |  $2^{315360*10^8}$  |    $2^{31556736*10^8}$    |
| ${n}^{1/2}$ |   $10^12$    |  $36*10^{14}$  | $1296*10^{16}$ | $746496*10^{16}$ | $6718464*10^{18}$ | $994519296*10^{18}$ | $995827586973696*10^{16}$ |
|     $n$     |    $10^6$    |    $6*10^7$    |   $36*10^8$    |    $864*10^8$    |    $2592*10^9$    |    $31536*10^9$     |      $31556736*10^8$      |
|  $n\lg n$   |   $62746$    |   $2801417$    |  $133378058$   |   $2755147513$   |   $71870856404$   |   $797633893349$    |     $68654697441062$      |
|    $n^2$    |    $1000$    |     $7745$     |    $60000$     |     $293938$     |     $1609968$     |      $5615692$      |        $56175382$         |
|    $n^3$    |    $100$     |     $391$      |     $1532$     |      $4420$      |      $13736$      |       $31593$       |         $146677$          |
|   $2^n $    |     $19$     |      $25$      |      $31$      |       $36$       |       $41$        |        $44$         |           $51$            |
|    $n!$     |     $9$      |      $11$      |      $12$      |       $13$       |       $15$        |        $16$         |           $17$            |

