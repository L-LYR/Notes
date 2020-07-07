# 梯度下降法及拓展

## 背景及假设

> 快速求得一个损失函数$\mathcal l(\mathbf w)$的极小值
>
> 损失函数性质：
>
> 1. 下凸
> 2. 连续
> 3. 可导（甚至二阶可导）

## 基本算法框架

> 1. 初始化$\mathbf w_0$
>
> 2. 进入循环直到收敛：$\mathbf w_{t+1} = \mathbf w_t + \mathbf s$，收敛条件$\| \mathbf w_{t+1}-\mathbf w_t \| \lt \epsilon_r$

## 泰勒展开式

这里直接给出1阶和2阶展开式，如下：
$$
\begin{align}
\mathcal l(\mathbf {w+s}) &= \mathcal l(\mathbf w) + \mathbf g(\mathbf w)^T\mathbf s\\
\mathcal l(\mathbf {w+s}) &= \mathcal l(\mathbf w) + \mathbf g(\mathbf w)^T\mathbf s + \frac{1}{2} \mathbf s ^ T \mathbf H(\mathbf w) \mathbf s\\
\end{align}
( \mathbf g(\mathbf w)=\nabla \mathcal l(\mathbf w), \mathbf H(\mathbf w) = \nabla ^ 2 \mathcal l(\mathbf w),\| \mathcal s \|\rightarrow 0)
$$

## 梯度下降法

这里仅使用1阶泰勒展开式，同时另
$$
\mathbf s = -\alpha \mathbf g (\mathbf w)\ (\alpha \gt 0)
$$
很显然有
$$
\begin{align}
\mathcal l(\mathbf {w+s}) &= \mathcal l(\mathbf w) + \mathbf g(\mathbf w)^T\mathbf s\\
&= \mathcal l(\mathbf w) -\alpha \mathbf g (\mathbf w) ^ T \mathbf g (\mathbf w) \lt \mathcal l(\mathbf w)
\end{align}
$$
这里$\alpha$被称作学习率，根据经验人为设定，一般来说会设置为$\alpha = \frac{t_0}{t}$，其中$t_0$是预设的正数，$t$是迭代次数，因为学习率的存在是为了快速收敛，这样设置会随迭代次数增长而逐渐变小，促进收敛。学习率过大则会使得过程不受控制。

## Adagrad算法

> 1. 初始化$\mathbf w_0$和$\mathbf z$：$w^0_d = 0,\ z_d=0$
> 2. 进入循环直至收敛，收敛条件$\| \mathbf w_{t+1} - \mathbf w_{t} \|_2 \lt \delta$
>    1. $\mathbf g = \frac{\partial f(\mathbf w)}{\partial \mathbf w}$
>    2. $\forall d: z_d = z_d + g_d^2$
>    3. $\forall d: w_d^{t+1} = w^t_d - \alpha \frac {g_d} {\sqrt{z_d+\epsilon}}$

## 牛顿法

这里将使用2阶泰勒展开式，如下
$$
\mathcal l(\mathbf {w+s}) = \mathcal l(\mathbf w) + \mathbf g(\mathbf w)^T\mathbf s + \frac{1}{2} \mathbf s ^ T \mathbf H(\mathbf w) \mathbf s
$$
对于$\mathbf H(\mathbf w)$来说，有
$$
H(\mathbf{w})=\left(\begin{array}{cccc}
\frac{\partial^{2} \ell}{\partial w_{1}^{2}} & \frac{\partial^{2} \ell}{\partial w_{1} \partial w_{2}} & \cdots & \frac{\partial^{2} \ell}{\partial w_{1} \partial w_{n}} \\
\vdots & \cdots & \cdots & \vdots \\
\frac{\partial^{2} \ell}{\partial w_{n} \partial w_{1}} & \cdots & \cdots & \frac{\partial^{2} \ell}{\partial w_{n}^{2}}
\end{array}\right)
$$
它一定是对称矩阵，同时因为$\mathcal l (\mathbf w)$的下凸性，$\mathbf H(\mathbf w)$一定是半正定的，即$\mathbf s ^ T \mathbf H(\mathbf w) \mathbf s \ge 0$，所以这个关于$\mathbf s$的抛物线，他的最小值点即为
$$
\begin{aligned}\frac
{\partial \mathcal l(\mathbf {w+s})}{\partial \mathbf s}=
g(\mathbf{w})+H(\mathbf{w}) \mathbf{s} &=0 \\
\Rightarrow \mathbf{s} &=-[H(\mathbf{w})]^{-1} g(\mathbf{w})
\end{aligned}
$$

那么为什么要找他的最小值点咧？

因为原意是寻找$\mathcal l(\mathbf w)$的极值，那么在假设之上可以等价于寻找$\frac{\mathrm d \mathcal l(\mathbf w)}{\mathrm d \mathbf w} = 0$，那就直接用牛顿法求根就行了。

在确保精确的前提下，这种方法收敛很快，但是在所有情况下，它并不能保证收敛，因为这里无法确保步长的极小性以及近邻性，而泰勒展开式的近邻性使得太大的步长会超出精确范围。