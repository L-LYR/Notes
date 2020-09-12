# 数值分析

## 引论

### 近似计算方法

1. 离散化：如定积分的计算
2. 递推化：如秦九韶算法
3. 近似替代：如泰勒展开式

### 误差

#### 来源

1. 模型误差：数学模型存在的误差，诸如理想化等方法导致。
2. 观测误差：原始数据必然由观测、度量和实验等得来，在此期间诸如译器精度等原因将导致的误差。
3. 截断误差：实际计算与理论推导不一致导致的误差，如无限项求和舍弃余项。
4. 舍入误差：计算条件限制导致计算数据字长有限，进而导致实际参与运算的数据是理论数据的逼近值产生的误差。

#### 定义

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