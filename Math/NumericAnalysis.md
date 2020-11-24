# 数值分析

## 引论

### 近似计算方法

1. 离散化：如定积分的计算
2. 递推化：如秦九韶算法
3. 近似替代：如泰勒展开式

### 误差

- 来源

1. 模型误差：数学模型存在的误差，诸如理想化等方法导致。
2. 观测误差：原始数据必然由观测、度量和实验等得来，在此期间诸如译器精度等原因将导致的误差。
3. 截断误差：实际计算与理论推导不一致导致的误差，如无限项求和舍弃余项。
4. 舍入误差：计算条件限制导致计算数据字长有限，进而导致实际参与运算的数据是理论数据的逼近值产生的误差。

- 定义

假设某个量的精确值为$x$，近似值为$x^*$，则定义绝对误差（简称误差）为
$$
\Delta (x^*) = x^*-x
$$
定义相对误差为
$$
\delta (x^*) = \frac{\Delta(x^*)}{x} \times 100\%
$$
若存在某一正数$\eta$，使得
$$
|\Delta(x^*)| \le \eta(x^*)
$$
则称$\eta(x^*)$为近似值$x^*$的绝对误差限（简称误差限）。

我们将相对误差限绝对值的上界称为相对误差限：
$$
\delta_r(x^*) = \frac{\Delta(x^*)}{|x^*|}\times 100\%
$$


注意：

1. 误差有正负，有量纲。
2. 误差限越小，近似值越精确。
3. 准确值总是不知道的，所以在相对误差较小的情况下，其分母可用近似值代替。
4. 误差限不唯一，因为他只是个上界，同时误差限是可确定的。

### 有效数字

精确值$x$的近似值$x^*$表示为
$$
x^* = \pm 0.a_1a_2\cdots a_n\times10^m
$$
其中$a_i$为数位，$a_1\ne 0$，那么当
$$
|x^*-x|\le \frac{1}{2}\times 10^{m-l}, (1\le l\le m)
$$
则$x^*$有$l$位有效数字。

### 有效数字与相对误差限的关系

设近似值$x^*= \pm 0.a_1a_2\cdots a_n\times10^m$，其中有$n$位有效数字，$a_1\ne 0$，则其相对误差为$\frac{1}{2a_1}\times 10^{-n+1}$。

设近似值$x^*= \pm 0.a_1a_2\cdots a_n\times10^m$，其相对误差限为$\frac{1}{2(a_1+1)}\times 10^{-n+1}$，$a_1\ne 0$，则它有$n$位有效数字。

这里的推导相对简单，略去。注意这两个定义并不是对称的，需要从不等式的不对称性来理解。

### 误差的传递

#### 加法与减法

$$
\begin{align}
\Delta (x* \pm y*) = (x^*\pm y^*) - (x\pm y) &= (x^*-x)\pm (y^* - y)\\
&= \Delta(x^*) \pm \Delta(y^*)
\end{align}
$$

$$
\begin{align}
|\Delta (x^* \pm y*)| = |(x^*\pm y^*) - (x\pm y)| &= |(x^*-x)\pm (y^* - y)|\\
&\le |\Delta(x^*)| + |\Delta(y^*)| \\ 
&\le \eta(x^*) + \eta(y^*)
\\\Rightarrow \eta(x^*\pm y^*) = \eta(x^*) + \eta(y^*)
\end{align}
$$

如上，加法和减法会将误差做相同的运算，而误差限均为原误差限的累加。

#### 乘法

$$
\begin{aligned}
\eta(x^*y^*)=|\Delta (x^*y^*)| = \left|x^{*} y^{*}-x y\right| &=\left|x^{*} y^{*}-x y^{*}+x y^{*}-x y\right| \\
&=\left|y^{*}\left(x^{*}-x\right)+x\left(y^{*}-y\right)\right| \\
& \leqslant\left|y^{*}\right| \cdot\left|x^{*}-x\right|+|x| \cdot\left|y^{*}-y\right| \\
& \leqslant\left|y^{*}\right| \cdot\left|x^{*}-x\right|+\left|x^{*}-x-x^{*}\right| \cdot\left|y^{*}-y\right| \\
& \leqslant\left|y^{*}\right| \cdot\left|x^{*}-x\right|+\left|x^{*}\right| \cdot\left|y^{*}-y\right|+\left|x^{*}-x\right| \cdot\left|y^{*}-y\right| \\
& \leqslant\left|y^{*}\right| \eta\left(x^{*}\right)+\left|x^{*}\right| \eta\left(y^{*}\right)+\eta\left(x^{*}\right) \eta\left(y^{*}\right)
\end{aligned}
$$

若满足$\eta(y^*)<<|y^*|$，$\eta(x^*)<<|x^*|$，则有
$$
|\Delta (x^*y^*)| \le \left|y^{*}\right| \eta\left(x^{*}\right)+\left|x^{*}\right| \eta\left(y^{*}\right) 
\Rightarrow  \eta(x^*y^*)\approx \left|y^{*}\right| \eta\left(x^{*}\right)+\left|x^{*}\right| \eta\left(y^{*}\right)
$$


#### 除法

$$
\begin{align}
|\Delta({\frac{x^*}{y^*}})| = |{\frac{x^*}{y^*}}-{\frac{x}{y}}|=&|{\frac{x^*}{y^*}}-{\frac{x^*-\Delta(x^*)}{y^*-\Delta(y^*)}}|
\\
=&|{\frac{x^*(y^*-\Delta(y^*))-y^*(x^*-\Delta(x^*))}{y^*(y^*-\Delta(y^*))}}|
\\
=&|\frac{-x^*\Delta(y^*)+y^*\Delta(x^*)}{{y^*}^2(1-\frac{\Delta(y^*)}{y^*})}|
\\
\le&\frac{|x^*||\Delta(y^*)|+|y^*||\Delta(x^*)|}{|y^*|^2|1-\frac{\Delta(y^*)}{y^*}|}
\\
\le&\frac{|x^*|\eta(y^*)+|y^*|\eta(x^*)}{|y^*|^2(1-\frac{\eta(y*)}{|y^*|})}

\end{align}
$$



若满足$\eta(y^*)<<|y^*|$，则有
$$
|\Delta({\frac{x^*}{y^*}})| \le \frac{|x^*|\eta(y^*)+|y^*|\eta(x^*)}{|y^*|^2} \Rightarrow \eta({\frac{x^*}{y^*}}) \approx \frac{|x^*|\eta(y^*)+|y^*|\eta(x^*)}{|y^*|^2}
$$

#### 可微函数

对于可微函数$y=f(x)$，根据中值定理有
$$
\Delta(y^*) = f(x^*)-f(x) = f'(\xi)(x^*-x)
$$
若$x^*\rightarrow x$，则有$f'(\xi)\approx f'(x^*)$，故有
$$
|\Delta(y^*)| \approx |f'(x^*)||x-x^*| \le |f'(x^*)|\eta(x^*)\Rightarrow \eta(y^*) = |f'(x^*)| \eta(x^*)
$$
注意对于其相对误差有
$$
\delta(y^*) = \frac{\Delta(y^*)}{y} \approx \frac{f'(x^*)(x^*-x)}{f(x)} = f'(x^*)\frac{x}{f(x)}\delta(x^*)
$$
推广至多元函数$y=f(x_1,x_2,\ldots,x_n)$有
$$
\Delta(y^*) = \sum_{k=1}^{n}\frac{\partial f(x_1^*,x_2^*,\ldots,x_n^*)}{\partial x_k}\Delta(x^*_k) \\
\delta(y^*) = \sum_{k=1}^n\frac{\partial f(x_1^*,x_2^*,\ldots,x_n^*)}{\partial x_k}\frac{x^*_k}{f(x_1^*,x^*_2,\ldots,x_n^*)}\delta(x^*_k)
$$

### 注意事项

1. 避免相近两数相减
2. 避免除数的绝对值远小于被除数的绝对值
3. 避免大数吃小数
4. 简化计算步骤，减少运算次数，进而减少误差积累
5. 选用稳定算法

## 插值方法

需求：求（逼近）解析式，求近似函数值。

前提：解析式存在且连续

情况：

1. 离散数据，无解析式
2. 解析式已知，但计算复杂

> 这里只涉及最基本的多项式插值方法

### 插值多项式

- 条件

插值节点：互异点$x_0,x_1,\ldots,x_n$

插值区间：包含插值节点的区间$[a,b]$

插值多项式：确定一个次数不高于$n$的代数多项式$P_n(x)=a_0+a_1x+a_2x^2+\ldots+a_nx^n$使得$P_n(x_i)=y_i$对$i\in{0,1,2,\ldots,n}$成立。

- 结论

**插值多项式存在且唯一**。

证明如下：

由条件式有
$$
\begin{cases}
P_n(x_0) = a_0 + a_1x_0 + a_2x_0^2 + \cdots + a_nx_0^n &= y_0 \\
P_n(x_1) = a_0 + a_1x_1 + a_2x_1^2 + \cdots + a_nx_1^n &= y_1 \\
& \vdots \\
P_n(x_n) = a_0 + a_1x_n + a_2x_n^2 + \cdots + a_nx_n^n &= y_n
\end{cases}
$$
对于这样一个关于$a_i$的线性方程组，若有解，则必须满足系数行列式不为零，而
$$
V = \left|\begin{array}{cccc}
 1 & x_0 & x_0^2 & \cdots & x_0^n\\
 1 & x_1 & x_1^2 & \cdots & x_1^n\\
 \vdots & \vdots & \vdots & \ddots & \vdots\\\
 1 & x_n & x_n^2 & \cdots & x_n^n\\
\end{array}\right| = \prod_{0\le i \lt j \le n} (x_j - x_i)
$$
由互异点可知$x_j\ne x_i$，则$V \ne 0$，说明该线性方程组有唯一解，也说明插值多项式存在且唯一。

### Lagrange插值

同上插值条件，Lagrange插值公式如下：
$$
p_x(x) = \sum_{i=0}^ny_i\left(\prod_{j=0 \\ j\ne i}^n \frac{x-x_j}{x_i - x_j} \right)
$$
其中我们把
$$
l_i(x) =\prod_{j=0 \\ j\ne i}^n \frac{x-x_j}{x_i - x_j}
$$
称作Lagrange插值的插值基函数，他具有以下性质：
$$
l_i(x_i) = \begin{cases}
1&,j = i\\
0&,j\ne i
\end{cases}
$$
设$f(x)$在插值区间上有$n+1$阶导数，插值余项为
$$
R_n(x) = f(x) - p_n(x) = \frac{f^{n+1}(\xi)}{(n+1)!}\prod_{i=0}^n(x-x_i),\xi\in(a,b)
$$
证明如下：

**TODO**（罗尔定理）

### Newton插值

#### 差商

在给定闭区间上，有互异点$x_0,x_1,\ldots,x_n$，以及函数$f(x)$，则
$$
f[x_0, x_1]=\frac{f(x_0)-f(x_1)}{x_0-x_1}
$$
称为$f(x)$在$x_0,x_1$两点的一阶差商。
$$
f(x_0,x_1,x_2)=\frac{f[x_0,x_1]-f[x_1,x_2]}{x_0-x_2}
$$
称为$f(x)$在$x_0,x_1,x_2$三点的二阶差商。

一般地，
$$
f[x_0,x_1,\ldots,x_n] = \frac{f[x_0,x_1,\ldots,x_{n-1}] - f[x_1,x_2,\ldots,x_n]}{x_0-x_n}
$$
称为$f(x)$在$x_0,x_1,\ldots,x_n$这$n+1$个点的$n$阶差商，为统一起见，称$f(x)$在$x_i$处的函数值称为在该点的0阶差商。

以下给出差商的性质：

1. 差商是对应点的函数值的线性组合（数学归纳法）

$$
f[x_0,x_1,\ldots,x_n] = \sum_{j=0}^n\frac{f(x_j)}{\prod_{i=0\\i\ne j}^n(x_j-x_i)}
$$

若令
$$
w_n(x) = \prod_{i=0}^n(x-x_i)
$$
则有
$$
w'_n(x) = \sum_{l=0}^n\prod_{i=0\\i\ne l}^n(x-x_i)
$$
进一步有
$$
w_n'(x_j) = \prod_{i=0\\i\ne j}^n(x_j-x_i)
$$
所以有
$$
f[x_0,x_1,\ldots,x_n] = \sum_{j=0}^n\frac{f(x_j)}{\prod_{i=0\\i\ne j}^n(x_j-x_i)} = \sum_{j=0}^n\frac{f(x_j)}{w'_n(x_j)}\\
R_n(x) = \frac{f^{n+1}(\xi)}{(n+1)!}w_n(x)
$$

2. 差商的点的序列中可以任意改变顺序而不改变差商的值，即（用差商的定义证明）

$$
f[x_0,x_1,\ldots,x_n] = f[x_1,x_0,x_2,\ldots,x_n] = \cdots = f[x_n,x_{n-1},\ldots,x_0]
$$

3. 如果$f[x,x_0,x_1,\ldots,x_n]$是$x$的$m$次多项式，则$f[x,x_0,x_1,\ldots,x_n,x_{n+1}]$是$x$的$m-1$次多项式。（用差商定义证明）
4. 如果$f(x)$是$x$的$n$次多项式，则$f[x,x_0,x_1,\ldots,x_n]$恒等于0。

根据差商的定义，有
$$
\begin{aligned}
f(x)  = & f(x_0) + f[x, x_0](x-x_0)\\
 	  = & f(x_0) + f[x_0, x_1](x-x_0) + f[x,x_0,x_1](x-x_0)(x-x_1) \\
 	 \vdots \quad = &\quad \vdots \\
 	  = & f(x_0) + f[x_0, x_1](x-x_0) + f[x_0,x_1,x_2](x-x_0)(x-x_1) + \cdots \\
 	    & + f[x_0, x_1,\ldots,x_n](x-x_0)(x-x_1)\cdots(x-x_{n-1}) \\
 	    & + f[x,x_0,x_1,\ldots,x_n](x-x_0)(x-x_1)\cdots(x-x_{n-1})(x-x_n)
\end{aligned}
$$
记Newton插值公式为
$$
N_n(x) = f(x_0) + f[x_0, x_1](x-x_0) + f[x_0,x_1,x_2](x-x_0)(x-x_1) + \cdots + f[x_0, x_1,\ldots,x_n](x-x_0)(x-x_1)\cdots(x-x_{n-1})
$$
其余项即为
$$
R_n(x) = f(x) - N_n(x) = f[x,x_0,x_1,\ldots,x_n](x-x_0)(x-x_1)\cdots(x-x_{n-1})(x-x_n) = f[x,x_0,x_1,\ldots,x_n]w_n(x)
$$
根据插值多项式的唯一性有
$$
N_n(x) = p_n(x)
$$
进一步可知余项也应相等，所以有如下定理：

在插值节点所规定的范围$[\min_{0\le i\le n}x_i,\max_{0\le i\le n}x_i]$必存在一点$\xi$，使得
$$
f[x_0,x_1,\ldots,x_n] = \frac{f^{n}(\xi)}{(n)!}
$$

### Hermit插值

上述插值方法和分段线性插值的方法都无法保证在插值点的光滑性，因此Hermit插值给出了更加严格的要求，如下：

在上述插值条件下，要求：
$$
H(x_i) =  f(x_i) \quad H'(x_i)=f'(x_i) \quad (i\in{0,1,2,\ldots,n})
$$
设两类基函数满足下式：
$$
\begin{cases}
\alpha_i(x_j) = \begin{cases}
	0\quad i\ne j\\
	1\quad i = j
\end{cases}\\
\alpha'_i(x_j) = 0\\
\beta_i(x_j) = 0\\
\beta_i'(x_j)=\begin{cases}
	0\quad i\ne j\\
	1\quad i = j
\end{cases}\\
\end{cases}
$$
如此以来，$H(x)$可表示为：
$$
H(x) = \sum_{i=0}^{n}[f(x_i)\alpha_i(x) + f'(x_i)\beta_i(x)]
$$
因此只需要求出基函数即可，这里采用构造法，如下：
$$
\alpha_i(x) = (a_1x+b_1)l_i^2(x)\\
\beta_i(x) = (a_2x+b_2)l_i^2(x)
$$
因为$\alpha_i(x_i)=1,\alpha_i'(x_i)=0$，有
$$
\begin{cases}
(a_1x+b_1)=1\\
a_1l_i^2(x_i)+2(a_1x_i+b_1)l_i(x_i)l'_i(x_i)=0
\end{cases}\Rightarrow 
\begin{cases}
(a_1x+b_1)=1\\
a_1+2l'_i(x_i)=0
\end{cases}
$$
因此得到：
$$
\alpha_i(x) = [1-2(x-x_i)\sum_{k=0\\k\ne i}^n\frac{1}{x_i-x_k}]l_i^2(x)
$$
同理得：
$$
\beta_i(x) = (x-x_i)l_i^2(x)
$$
故
$$
H_{2 n+1}(x)=\sum_{i=0}^{n}\left\{f\left(x_{i}\right)\left[1-2\left(x-x_{i}\right) \sum_{k=0 \atop k \neq i}^{n} \frac{1}{x_{i}-x_{k}}\right]l_{i}^{2}(x)+f^{\prime}\left(x_{i}\right)\left(x-x_{i}\right)l_{i} ^{2}(x)\right\}
$$
设$f(x)$在插值区间上有$2n+2$阶导数，则插值余项为
$$
R_{2 n+1}(x)=f(x)+H_{2 n+1}(x)=\frac{f^{(2 n+2)}(\xi)}{(2 n+2) !} w_n^{2}(x)
$$
上述构造法给予了我们一种待定系数求插值多项式的方法，这里给出一个简单的例子：

插值条件：$H_4(0)=0,H_4(1)=1,H_4(2)=1,H'_4(0)=0,H_4'(1)=1$

解：设
$$
H_4(x) = f(x_0)\alpha_0(x)+f(x_1)\alpha_1(x)+f(x_2)\alpha_2(x)+f'(x_0)\beta_0(x)+f'(x_1)\beta_1(x)\\
\Rightarrow H_4(x) = \alpha_1(x) + \alpha_2(x) + \beta_1(x)
$$
则有
$$
\begin{cases}
\alpha_{1}(0)=\alpha_{1}(2)=0, \alpha_{1}(1)=1 \\
\alpha_{1}(0)=\alpha_{1}(1)=0
\end{cases} \Rightarrow \alpha_1(x) = (ax+b)(x-0)^2(x-2)\Rightarrow \alpha_1(x) = x^2(x-2)^2
\\
\begin{cases}
\alpha_{2}(0)=\alpha_{2}(1)=0, \alpha_{2}(2)=1 \\
\alpha_{2}(0)=\alpha_{2}(1)=0
\end{cases} \Rightarrow \alpha_2(x)=c(x-0)^2(x-1)^2 \Rightarrow \alpha_2(x) = \frac{1}{4}x^2(x-1)^2
\\
\begin{cases}
\beta_{1}(0)=\beta_{1}(1)=\beta_{1}(2)=0 \\
\beta_{1}(0)=0, \beta_{1}(1)=1
\end{cases} \Rightarrow \beta_1(x) = d(x-0)^2(x-1)(x-2) \Rightarrow \beta_1(x) = -x^2(x-1)(x-2)
$$
因此
$$
H_4(x) = \frac{1}{4}x^4 - \frac{3}{2}x^3 + \frac{9}{4}x^2
$$

### 分段插值

由于存在Runge现象，在大范围内使用高次插值，逼近的效果反而不太理想，因此要避免使用高次的插值逼近，进而提出了分段低次插值的方法，其步骤为

1. 对插值区间$[a,b]$进行划分$\Phi:a=x_0\lt x_1 \lt \ldots < x_n = b$。
2. 在每个小区间$[x_j,x_{j+1}]$上构造低次插值多项式$P_i(x)$。
3. 将每个$p_i(x)$拼接为$[a,b]$上的分段多项式$S_k(x)$作为$f(x)$的插值函数，前者也被称为分段k次式。

#### 分段线性插值

分段低次插值的分段k次式为1次时的插值。

若目标函数在插值区间二次可导，则有
$$
\left|f(x) - S_1(x)\right| \le \frac{1}{8}h^2\max_{a\le x\le b}|f''(x)|\\ h = \max(h_i), h_i = x_{i + 1} - x_i, i= 0,1,\ldots,n-1
$$
**TODO**（利用余项公式）

这个不等式说明，分段线性插值逼近目标函数时拥有一个与自变量无关的上界，同时这个上界依赖于对插值区间的划分密度，因此当对插值区间密度提高，划分子区间的长度趋于0时，分段线性插值函数一致收敛于目标函数，能够使得结果达到任意的精度。

#### 分段三次插值

在每个分段中使用Hermit插值，即
$$
\begin{array}{l}
H_{3}(x)=f\left(x_{0}\right) a_{0}(x)+f\left(x_{1}\right) a_{1}(x)+f^{\prime}\left(x_{0}\right) \beta_{0}(x)+f^{\prime}\left(x_{1}\right) \beta_{1}(x) \\
a_{0}(x)=\left(1+2 \frac{x-x_{0}}{x_{1}-x_{0}}\right)\left(\frac{x-x_{1}}{x_{0}-x_{1}}\right)^{2} \\
a_{1}(x)=\left(1+2 \frac{x-x_{1}}{x_{0}-x_{1}}\right)\left(\frac{x-x_{0}}{x_{1}-x_{0}}\right)^{2} \\
\beta_{0}(x)=\left(x-x_{0}\right)\left(\frac{x-x_{1}}{x_{0}-x_{1}}\right)^{2} \\ \beta_{1}(x)=\left(x-x_{1}\right)\left(\frac{x-x_{0}}{x_{1}-x_{0}}\right)^{2} \\
R_{3}(x)=f(x)-H_{3}(x)=\frac{f^{(4)}(\xi)}{4 !}\left(x-x_{0}\right)^{2}\left(x-x_{1}\right)^{2} \quad (x_{0}<\xi<x_{1})
\end{array}
$$
这里的区间为$[x_0,x_1]$，设$h = x_1 - x_0$，则$x = x_0 + th, t \in [0, 1]$，因此只需要在$[0,1]$上插值就好了，这里可以直接按上一节的计算方法得到：
$$
\left\{\begin{array}{l}
\alpha_{0}(t)=(t-1)^{2}(2 t+1) \\
\alpha_{1}(t)=t^2(-2t+3)
\end{array}\right.
\left\{\begin{array}{l}
\beta_{0}(t)=t(t-1)^{2} \\
\alpha_{1}(t)=t^{2}(-2 t+3)
\end{array}\right.
$$
那么分段三次插值的式子即为
$$
S_3^i(x) = y_i\alpha_0(\frac{x-x_i}{h_i}) + y_{i+1}\alpha_1(\frac{x-x_i}{h_i}) + h_iy_i'\beta_0(\frac{x-x_i}{h_i}) + h_iy_{i+1}'\beta_1(\frac{x-x_i}{h_i})\\
x\in[x_i,x_{i+1}],h_i = x_{i + 1} - x_i, i= 0,1,\ldots,n-1
$$
若目标函数在插值区间四次可导，则有
$$
|f(x) - S_3(x)| \le \frac{1}{384}h^4\max_{a\le x\le b}|f^{(4)}(x)|, h = \max h_i
$$

#### 分段样条插值

更进一步，为了更光滑，样条插值所得到的分段三次式在各个互异点上都有二阶导数，同时与目标函数的导数值相等。

### 最小二乘法

#### 直线拟合



#### 曲线拟合

