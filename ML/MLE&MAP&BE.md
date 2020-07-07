# MLE&MAP&BE

- Frequentist - Maximum Likelihood Estimation (MLE，最大似然估计)

- Bayesian - Maximum A Posteriori (MAP，最大后验估计)

- True Bayesian - Bayesian Estimation (BE，贝叶斯估计)

## 两大学派的争论

抽象一点来讲，频率学派和贝叶斯学派对世界的认知有本质不同：频率学派认为世界是确定的，有一个本体，这个本体的真值是不变的，目标就是要找到这个真值或真值所在的范围；而贝叶斯学派认为世界是不确定的，人们对世界先有一个预判，而后通过观测数据对这个预判做调整，目标是要找到最优的描述这个世界的概率分布。

实际情况是，对事物建模之后，模型的参数$\theta$的存在观点如下：

频率学派认为，$\theta$是存在唯一真值的，是一个固定的值，并且是可以从现有的数据直观得出。比如投硬币实验中正面朝上的概率可以通过古典概型直观求得。

贝叶斯学派认为，$\theta$是一个随机变量，是符合一定的概率分布的。其理论基础便是贝叶斯公式：
$$
P(\theta | X)=\frac{P(X | \theta) \cdot P(\theta)}{P(X)}
$$
有两点值得注意的地方：

- 随着数据量的增加，参数分布会越来越向数据靠拢，先验的影响力会越来越小
- 如果先验是uniform distribution，则贝叶斯方法等价于频率方法。因为直观上来讲，先验是uniform distribution本质上表示对事物没有任何预判。

## 名词解释

- 联合概率（多个随机变量，多个事件）与边缘概率（单个随机变量，单个事件）

$$
\begin{aligned}
&P(A=a)=\sum_{b} P(A=a, B=b)\\
&P(A=b)=\sum_{a} P(A=a, B=b)
\end{aligned}
$$

- 条件概率

$$
P(A | B)=\frac{P(A, B)}{P(B)}
$$

- 全概率公式

全概率公式是对复杂事件$A$的概率求解问题转化为了在不同情况下发生的简单事件的概率的求和问题。
$$
P(B)=P\left(B | A_{1}\right) P\left(A_{1}\right)+P\left(B | A_{2}\right) P\left(A_{2}\right)+\ldots+P\left(B | A_{n}\right) P\left(A_{n}\right)=\sum_{i=1}^{n} P\left(B | A_{i}\right) P\left(A_{i}\right)
$$

- 贝叶斯公式

$$
P(A | B)=\frac{P(B | A) \cdot P(A)}{P(B)}
$$

$P(A|B)$是$B$发生后$A$发生的条件概率，$A$的后验概率。

$P(A)$是$A$的边缘概率，$A$的先验概率。

$P(B|A)$是$A$发生后$B$发生的条件概率，$B$的后验概率。

$P(B)$是$B$的边缘概率，$B$的先验概率。



## MLE

假设数据$x_1,x_2,\dots,x_n$是一组独立同分布（$i.i.d$）的抽样，记为$X=(x_1,x_2,\dots,x_n)$，那么参数$\theta$的MLE估计方法如下：
$$
\begin{aligned}
\hat{\theta}_{\mathrm{MLE}} &=\arg \max P(X ; \theta) \\
&=\arg \max \prod_{i=1}^{n} P\left(x_{i} ; \theta\right) \\
&=\arg \max \log \prod_{i=1}^{n} P\left(x_{i} ; \theta\right) \\
&=\arg \max \sum_{i=1}^{n} \log P\left(x_{i} ; \theta\right) \\
&=\arg \min -\sum_{i=1}^{n} \log P\left(x_{i} ; \theta\right)
\end{aligned}
$$
最后这一行所优化的函数被称为Negative Log Likelihood (NLL)，这个概念和上面的推导是非常重要的！

## MAP

假设同上，MAP估计方法如下：
$$
\begin{aligned}
\hat{\theta}_{\mathrm{MAP}} &=\arg \max P(\theta | X) \\
&=\arg \min -\log P(\theta | X) \\
&=\arg \min -\log P(X | \theta)-\log P(\theta)+\log P(X) \\
&=\arg \min -\log P(X | \theta)-\log P(\theta)
\end{aligned}
$$
**注意：$-\log P(X|\theta)$其实就是NLL，所以MLE和MAP在优化时的不同就是在于先验项$-\log P(\theta)$。**

## BE

贝叶斯估计是最大后验估计(MAP)的进一步扩展，和MAP一样，也认为参数$\theta$不是固定的，都假设参数服从一个先验分布。但是MAP是直接估计出参数的值，而贝叶斯估计是估计出参数的分布，这就是贝叶斯与MLE与MAP最大的不同，所以在贝叶斯估计中，先验分布$\log P(X)$是不可忽略的。

对于连续型随机变量，有
$$
P(X)=\int_{\Theta} P(X | \theta) P(\theta) d \theta
$$
因此贝叶斯公式变为
$$
P(\theta | X)=\frac{P(X | \theta) P(\theta)}{P(X)}=\frac{P(X | \theta) P(\theta)}{\int_{\Theta} P(X | \theta) P(\theta) d \theta}
$$
贝叶斯估计要解决的不是如何估计参数，而是用来估计新测量数据出现的概率，对于新出现的数据$\tilde x$：
$$
P(\tilde{x} | X)=\int_{\Theta} P(\tilde{x} | \theta) P(\theta | X) d \theta=\int_{\Theta} P(\tilde{x} | \theta) \frac{P(X | \theta) P(\theta)}{P(X)} d \theta
$$
BE的基本步骤

- 确定参数的似然函数
- 确定参数的先验分布，应是后验分布的共轭先验
- 确定参数的后验分布函数
- 根据贝叶斯公式求解参数的后验分布

# 摘录文章

https://zhuanlan.zhihu.com/p/32480810

[http://noahsnail.com/2018/05/17/2018-05-17-%E8%B4%9D%E5%8F%B6%E6%96%AF%E4%BC%B0%E8%AE%A1%E3%80%81%E6%9C%80%E5%A4%A7%E4%BC%BC%E7%84%B6%E4%BC%B0%E8%AE%A1%E3%80%81%E6%9C%80%E5%A4%A7%E5%90%8E%E9%AA%8C%E6%A6%82%E7%8E%87%E4%BC%B0%E8%AE%A1/](http://noahsnail.com/2018/05/17/2018-05-17-贝叶斯估计、最大似然估计、最大后验概率估计/)

https://zhuanlan.zhihu.com/p/72370235