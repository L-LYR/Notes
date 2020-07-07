## 计数技术基础

### 加法原理、乘法原理、容斥原理

分类加法原理累加情况，分步乘法原理累积情况。

注：

1. 分类之间无交集，否则考虑容斥原理。
2. 结合使用时要保证顺序：先分类之后类内分步，先分步之后每步分类。
3. 容斥原理即是减去重复计数的部分。

### 抽屉原理

> 将$k+1$个物体对象放入$k$个盒子,那么至少有一个盒子有多余一个的物体。
>
> 广义：如果$N$个物体放置到$k$个盒子中，那么至少有一个盒子装有不少于$\lceil N/k \rceil $个物体。
>
> 拉姆齐理论(Ramsey Theory)

抽屉原理的应用主要是考虑如何构造对象和盒子才能使用该定理。譬如连续严格递增序列。

### 排列&组合

最基础的无放回的无重复的$n$元素$r$有序与无序选取：
$$
P(n,r)=\frac{n!}{(n-r)!}\\
C(n,r)=\frac{n!}{r!(n-r)!}
$$
有重复的$n$元素$r$有序与无序选取：
$$
n^r\\
C(n-1+r,r)=C(n-1+r,n-1)
$$
$n$元素$r$圆排列：
$$
\frac{n!}{r(n-r)!}
$$
不可辨别的对象集合的排列：

$n$个对象有$k$个类型对应$n_k$个进行排列
$$
\frac{n!}{n_1!n_2!\cdots n_k!}
$$
$n$个不同（可辨别）的对象放入$k$不同（可辨别）的盒子
$$
\frac{n!}{n_1!n_2!\cdots n_k!}
$$
$n$个相同（不可辨别）的对象放入$k$不同（可辨别）的盒子
$$
C(n-1+k,k)=C(n-1+k,n-1)
$$
$n$个不同（可辨别）的对象放入$k$相同（不可辨别）的盒子

$n$个相同（不可辨别）的对象放入$k$相同（不可辨别）的盒子

### 组合证明法

该方法不使用代数技巧而是基于等式两边的对象集合来寻找满足恒等式的双射函数或者计数方法。

常见证明：
$$
C(n,r)=C(n,n-r)（子集的取法与子集补集的关系）
\\
\left(\begin{array}{l}{n} \\ {r}\end{array}\right)\left(\begin{array}{l}{r} \\ {k}\end{array}\right)=\left(\begin{array}{l}{n} \\ {k}\end{array}\right)\left(\begin{array}{l}{n-k} \\ {r-k}\end{array}\right)（分步取子集，考虑去重方案）
\\
(x+y)^{n}=\sum_{k=0}^{n}\left(\begin{array}{l}{n} \\ {k}\end{array}\right) x^{k} y^{n-k}(每一项的取法)
\\
\sum_{l=k}^{n}\left(\begin{array}{l}{l} \\ {k}\end{array}\right)=\left(\begin{array}{l}{n+1} \\ {k+1}\end{array}\right), \quad n, k \in N
\\
(讨论含r+1个1的长为n+1的位串中最后一个1的位置)
\\
\left(\begin{array}{l}{n} \\ 
{k}\end{array}\right)=\frac{n}{k}\left(\begin{array}{l}{n-1} \\ {k-1}\end{array}\right)
\\
(这就是乘积转换式中r换成k，k换成1的特殊情况，考虑分步去重即可)
\\
\left(\begin{array}{l}{n} \\ {k}\end{array}\right)=\left(\begin{array}{c}{n-1} \\ {k}\end{array}\right)+\left(\begin{array}{c}{n-1} \\ {k-1}\end{array}\right)(分情况取子集个数)
\\
\sum_{k=0}^{r}\left(\begin{array}{c}{m} \\ {k}\end{array}\right)\left(\begin{array}{c}{n} \\ {r-k}\end{array}\right)=\left(\begin{array}{c}{m+n} \\ {r}\end{array}\right) \quad m, n, r \in N, \quad r \leq \min (m, n)
\\
(俩集合取子集，考虑分步累和即可)
$$

### 二项式定理

$$
(x+y)^{n}=\sum_{k=0}^{n}\left(\begin{array}{l}{n} \\ {k}\end{array}\right) x^{k} y^{n-k}
$$

注意常对式中$x,y$取特定的值来获取一些数值等式。

### 生成排列和组合

字典序和二进制串，较简单，略。

## 高级计数技术

### 递推关系

最重要的就是建模，这个主要考虑如下三点：

1. 确定递推关系的初始状态
2. 确定问题规模为$n$的状态和问题规模为$n-1$的状态之间的关系，最好使用状态转移图来分析
3. 根据题目必要来求解（通项、某一项的值等）

### 常系数线性齐次递推方程

$$
\left\{\begin{array}{l}{a_{n}=c_{1} a_{(n-1)}+c_{2} a_{(n-2)}+\ldots+c_{k} a_{(n-k)}} \\ {a_{0}=b_{0}, a_{1}=b_{1}, a_{2}=b_{2}, \ldots, a_{k-1}=b_{k-1}}\end{array}\right.
$$

其特征方程为
$$
\mathbf{r}^{\mathbf{k}}-\mathbf{c}_{1} \mathbf{r}^{\mathbf{k}-1}-\mathbf{c}_{2} \mathbf{r}^{\mathbf{k}-2}-\ldots-\mathbf{c}_{\mathbf{k}-1} \mathbf{r}-\mathbf{c}_{\mathbf{k}}=\mathbf{0}
$$
其根即为特征根。

接下来考虑二阶常系数线性齐次递推方程$a_{n}=c_{1} a_{n-1}+c_{2} a_{n-2}$，则其特征方程如下：
$$
r^{2}-c_{1} r-c_{2}=0 
$$
得其俩不等根$r_1,r_2$即有以下满足原递推关系的通解：
$$
a_{n}=\alpha_{1} r_{1}^{n}+\alpha_{2} r_{2}^{n}
$$
若为等根$r_0$，则满足：
$$
a_{n}=\alpha_{1} r_{0}^{n}+\alpha_{2} n r_{0}^{n}
$$
而其中的系数$\alpha_1 , \alpha_2$由已知条件解得。

对于高阶的同理可推知，如下
$$
\begin{aligned} a_{n}=&\left(\alpha_{1,0}+\alpha_{1,1} n+\cdots+\alpha_{1, m_{1}-1} n^{m_{1}-1}\right) r_{1}^{n} \\ &+\left(\alpha_{2,0}+\alpha_{2,1} n+\cdots+\alpha_{2, m_{2}-1} n^{m_{2}-1}\right) r_{2}^{n} \\ &+\cdots+\left(\alpha_{t, 0}+\alpha_{t, 1} n+\cdots+\alpha_{t, m_{t}-1} n^{m_{t}-1}\right) r_{t}^{n} \end{aligned}
$$
其中$r_t$为特征根，$m_t$为相应重数，$\alpha_{i,j}$为相应初始条件确定的系数。

对于常系数线性非齐次递推方程则先解其导出的齐次递推，再加入特解即可。

其中当其非齐次项为$(b_tn^t+b_{t-1}n^{t-1}+\cdots+b_1n+b_0)s^n$且相伴特征方程的根不含$s$时，特解的形式为
$$
(p_tn^t+p_{t-1}n^{t-1}+\cdots + p_1n+p_0)s^n
$$
而当$s$是相伴特征方程的$m$重根时，特解的形式为
$$
n^m(p_tn^t+p_{t-1}n^{t-1}+\cdots + p_1n+p_0)s^n
$$

### 生成函数

实数序列$a_1,a_2,\ldots,a_n$的生成函数为
$$
G(x)=a_{0}+a_{1} x+a_{2} x^{2}+\ldots+a_{n} x^{n}+\ldots
$$

#### 广义二项式定理

$$
(1+x)^{\alpha}=\sum_{k=0}^{\infty}\left(\begin{array}{l}{u} \\ {k}\end{array}\right) x^{k}
$$

### 容斥原理

$$
\begin{array}{l}{\left|A_{1} \cup A_{2} \cup \cdots \cup A_{n}\right|=\sum_{1 \leq i \leq n}\left|A_{i}\right|-\sum_{1 \leq i \leq j \leq n}\left|A_{i} \cap A_{j}\right|+} \\ {\quad \sum_{1 \leq i \leq j \leq k \leq n}\left|A_{i} \cap A_{j} \cap A_{k}\right|-\ldots+(-1)^{n+1}\left|A_{1} \cap A_{2} \cap \ldots \cap A_{n}\right|}\end{array}
$$

1. 求满射个数
   $$
   n^{m}-C(n, 1)(n-1)^{m}+C(n, 2)(n-2)^{m}-\cdots+(-1)^{n-1} C(n, n-1) \cdot 1^{m}
   $$

2. 错位排列
   $$
   D_{n}=n !\left[1-\frac{1}{1 !}+\frac{1}{2 !}-\frac{1}{3 !}+\cdots+(-1)^{n} \frac{1}{n !}\right]
   $$

3. 变形
   $$
   \begin{aligned} N\left(P_{1}^{\prime} P_{2}^{\prime} \ldots P_{n}^{\prime}\right)=N-& \sum_{1 \leq i \leq n} N\left(P_{i}\right)+\sum_{1 \leq i<j \leq n} N\left(P_{i} P_{j}\right) \\ &-\sum_{1 \leq i<j<k \leq n} N\left(P_{i} P_{j} P_{k}\right)+\cdots+(-1)^{n} N\left(P_{1} P_{2} \ldots P_{n}\right) \end{aligned}
   $$

