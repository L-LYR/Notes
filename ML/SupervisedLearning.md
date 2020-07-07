# 监督学习简介

## 数据集

输入样本（特征向量）$\mathbf{x}\in \mathcal{R}^d$，对应标签$y$，$d$维特征空间$\mathcal{R}^d$，标签空间$\mathcal{C}$，训练集定义如下：
$$
D=\left\{\left(\mathbf{x}_{1}, y_{1}\right), \ldots,\left(\mathbf{x}_{n}, y_{n}\right)\right\} \subseteq \mathcal{R}^{d} \times \mathcal{C}
$$
其中有$(\mathbf{x}^d,y)\sim \mathcal{P}(X,Y)$，这个分布是无所谓明确或者不明确，我们的最终目的是寻找一个函数能够将新的输入赋予对应或者接近的标签，即$h(\mathbf{x}')=y'\ $或者$ \ h(\mathbf{x'})\approx y' $。

### 标签空间

根据分类任务的不同而选取不同的标签空间。

1. 二分类：$\mathcal{C}=\{0,1\}$或者$\mathcal{C}=\{-1,+1\}$
2. 多类别分类：$\mathcal{C} = {1,2,3,\ldots,K}(K\ge2)$
3. 回归：$\mathcal{C} = \R$

### 样本

样本$\mathbf{x}$是包含样本全部特征的特征向量，每一个分量都是该样本的一个特征（值）。

### 划分

一般来说数据集以$8:1:1$的比例划分为训练集$\mathcal D_{TR}$、验证集$\mathcal D_{VA}$和测试集$\mathcal D_{TE}$，用训练集寻找目标函数，用测试集来评估目标函数，用验证集来反复验证目标函数。

划分方案尽量做到随机均匀，不应按字母或者依据特征值。如果数据与有时间顺序，必须按时间分割。

## 目标函数

$$
\mathbf{h}=\arg \min _{\mathbf{h} \in \mathcal{H}} \mathcal{L}(\mathbf{h})
$$

其中$\mathcal H$是假想集，$\mathcal L$是损失函数，$\mathbf h$是目标函数。

### 假设集

在寻找目标函数之前，我们必须确定寻找的方向，也就是说，我们需要对目标函数做出假设“他是什么类型的”，比如神经网络，决策树或者其他类型的分类器。我们将这些可能的函数集合称为假设集。

### 损失函数

寻找目标函数的过程中有很重要的两个步骤，一是我们选择针对该问题的合适算法，进而可以定义假设集，二是实际的学习过程（常常会涉及到最优化问题）。基本上，我们会基于选定的训练集寻找到一个出错最少的函数。因此，针对寻找最优函数这一问题，我们需要某种方法来评估，于是我们会用到损失函数。损失函数可以告诉我们，基于选定的训练集，当前的假设函数好不好（损失为0当然是最好的）。通常的做法是用训练样本总数$n$对损失进行标准化，这样输出将会表明每个样本的平均损失而与$n$无关。

#### 损失函数举例

1. 0-1损失函数
   1. 单纯反应假设函数在训练集上的错误率
   2. 常用于多类别分类或者二分类
   3. 不可微、非连续的。

$$
\mathcal{L}_{0 / 1}(h)=\frac{1}{n} \sum_{i=1}^{n} \delta_{h\left(\mathbf{x}_{i}\right) \neq y_{i}}, \text { where } \delta_{h\left(\mathbf{x}_{i}\right) \neq y_{i}}=\left\{\begin{array}{ll}
1, & \text { if } h\left(\mathbf{x}_{i}\right) \neq y_{i} \\
0, & \text { o.w. }
\end{array}\right.
$$

2. 平方损失函数
   1. 常用于回归问题（标签值为实数）
   2. 损失值非负
   3. 损失以绝对错误的平方增长，因此预测值与实际值太远会导致结果差距很大，预测值与实际值太接近又很难察觉错误

$$
\mathcal{L}_{s q}(h)=\frac{1}{n} \sum_{i=1}^{n}\left(h\left(\mathbf{x}_{i}\right)-y_{i}\right)^{2}
$$

3. 绝对损失函数
   1. 常用于回归问题
   2. 损失值非负
   3. 损失与绝对错误呈线性增长，更适合噪声数据（部分错误不可避免且不应主导损失）

$$
\mathcal{L}_{a b s}(h)=\frac{1}{n} \sum_{i=1}^{n}\left|h\left(\mathbf{x}_{i}\right)-y_{i}\right|
$$

### 泛化

泛化指目标函数对新样本（训练集之外的输入）的适应能力。泛化能力弱的三种体现：欠拟合、过拟合、不收敛。

## 过程总结

在训练集上训练模型，最初的目标是最小化训练误差。
$$
h^{*}(\cdot)=\operatorname{argmin}_{h(\cdot) \in \mathcal{H}} \frac{1}{\left|D_{\mathrm{TR}}\right|} \sum_{(\mathbf{x}, y) \in D_{\mathrm{TR}}} \ell(\mathbf{x}, y | h(\cdot))
$$


在测试集上测试模型，计算测试误差。
$$
\epsilon_{\mathrm{TE}}=\frac{1}{\left|D_{T E}\right|} \sum_{(\mathbf{x}, y) \in D_{\mathrm{TE}}} \ell\left(\mathbf{x}, y | h^{*}(\cdot)\right)
$$
如果样本是独立同分布的，那么测试误差将会是泛化误差的无偏估计，这是由弱大数定律保证的。
$$
\epsilon=\mathbb{E}_{(\mathbf{x}, y) \sim \mathcal{P}}\left[\ell\left(\mathbf{x}, y | h^{*}(\cdot)\right)\right]\\
\epsilon_{\mathrm{TE}} \rightarrow \epsilon \text { as }\left|D_{\mathrm{TE}}\right| \rightarrow+\infty
$$
