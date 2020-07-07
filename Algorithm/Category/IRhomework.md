# 对PageRank算法的深入了解与一点想法

## 摘要

听了魏巍老师讲的信息检索以及相关算法，个人同时也对算法比较感兴趣，所以课下对PageRank算法进行的跟深入的了解和思考，本文主要记录了个人在课下了解的过程中的一些学习记录和思考结果。

## 目录

[TOC]

## 什么是PageRank?

> a method for rating Web pages objectively and mechanically, effectively measuring the human interest and attention devoted to them

以上是Larry Page在其论文中对他所创造出的PageRank算法的描述，由此我们很清晰地能了解到他的初衷——对网站进行排序。这也便是他所设计并研发的搜索引擎Google具备的主要而且主打的功能。

在PageRank被发明前，搜索引擎采用的都是最原始的关键字匹配技术，这种技术与网页内容不相关，因此有人恶意修改网页标题和内容，强行进入匹配度高的前列，导致用户搜索不到需要的网站，用户体验收到了极大的影响。对于这些垃圾网站，当时Yahoo使用的是人工清理的方法，而Larry Page想设计一种算法来解决这一问题，根据网页的重要性进行排序，从而便于用户查找。

## 基本思想

首先，我觉得非常直观的一点就是Larry Page在论文中提到的他所建立的一个模型——一个悠闲的上网冲浪者(*an idealized random Web surfer*)，指当他访问一个网页时，他对所有链接的点击都是等可能性的，是随机的，而我们的算法就是基于这样一个模型来计算这位上网者在各个页面的停留的概率。

其次，因为要计算这样一些概率，又需要用到马尔科夫链模型，这里还有一个假设，我们所计算的所有网页都是强连通的，也就是说通过一个网页都可以到达其他的所有网页。

接着，给出计算网页重要性传递的依据与方法。假设有两个网页A、B，如果网页B具有指向A的链接，则我们称A具有从B网站获得的一部分重要性，也就是上面提到的概率，该重要性取决于B网站自身的重要性以及B网站所拥有的链接数$n$，故A网站的重要性可以表示为$R(A)=R(B)/n$，其中$R(X)$表示网页X的重要性，$n$表示B网站所具有的链接数。显然，对于任意一个网站，其重要性是由所有指向他的网页所赋予它的重要性的累加值，因此我们有

$$
R(A_i)=\sum\frac{R(B_j)}{n_j}
$$
然后，我们将所有网页的链接情况用图的邻接矩阵表示
$$
M'=\left[ x_{A_{i}B_{j}}\right],其中\ x_{A_{i}B_{j}}=\begin{cases}1 \ \ \ \ \ (A_{i}B_{j}间有链接)\\ 0 \ \ \ \ \ (A_{i}B_{j}间无链接)\end{cases}
$$


根据上面假设的模型，点击链接是等可能的，即网页跳转等可能，则可得到以下转移矩阵
$$
M=\left[ x_{A_{i}B_{j}}\right],其中\ x_{A_{i}B_{j}}=\begin{cases}\frac{1}{n_i} \ \ \ \ \ (A_{i}B_{j}间有链接)\\ 0 \ \ \ \ \ (A_{i}B_{j}间无链接)\end{cases}
$$
初始时，对于这位上网者，他点击所有网站都是等可能性的，所以我们记初始的重要性为一个$m$维的列向量$X_0=[1/m,...,1/m]^T$，其中m为网页数。接着，用$X$不断去右乘$M$，即有迭代公式
$$
X'=MX
$$
最终收敛至恒定值，即为所求的重要性。

## 问题

由于我们使用的是理想模型，所以实际中存在一些极端的情况。

### Page Leak

这种情况是因为实际中页面与页面之间不是强连通的，存在一些页面他没有任何外链，当上网者进入这样一个网站后，上述操作就无法正常地进行下去，进而导致最后收敛值全为$0$。

### Page Sink

这种情况是因为有些网站虽然有外链但是却只链接自己，上网者进入这样的网站之后，就会进入陷阱，像漩涡一样，导致概率分布涌进，最后导致该网页的收敛值为$1$，而其余全是$0$。

针对以上两种问题，我们需要一位更聪明的上网者，对于迭代的每一步，上网者可能都想关闭当前网页了，不看当前网页也就可能降低点击陷阱链接的概率，而在网页池中随机选择一个网页跳转，同时在地址栏输入而跳转到各个网页的概率是$ \frac {1}{n}$。假设上网者每一步查看当前网页的概率为$a$，那么他从浏览器地址栏跳转的概率为$(1-a)$，于是原来的迭代公式转化为
$$
X'=aMX+(1-a)X_0
$$
这样我们就可以得到正确的目标收敛值了。

### 数据规模庞大

在实际的网络世界中，网页的链接是十分稀疏的，但网页的数量是及其庞大的，我们所构造出的转移矩阵也将会是稀疏的同时矩阵的维度也非常大，直接用矩阵乘法会导致计算效率低下，这里便需要Map-Reduce的计算方式来解决，以下是我学得的一种较简单的。

首先，考虑到我们所构建的转移矩阵是一个稀疏矩阵，所以我们用相应的列压缩的表示形式，即将web的链接图中的每一个网页作为第一列，而他所链出的网页作为相应的行，这样我们就得到了变形过后的web链接图。

接着，进入Map阶段。Map操作是逐行进行的，对所以每一行输出行首对应网页的重要性的$1/k$，$k$为该网页链出网页数。

最后，进入Reduce阶段。Reduce操作收集相同URL的网页所获得的重要性的值，按权重公式计算
$$
R(A_j)=\alpha \sum \frac{R(B_i)}{k_i}+ (1-\alpha)\frac{1}{n}
$$
其中，$A_j$指相同URL的网页，$R(B_i)$指网页$B_i$所对应的重要性，$k_i$指网页$B_i$所链出的网页数，$n$是所有网页数，$\alpha $是权重。

### 用户体验优化

在上面的描述中，我们一直没有点明我们所计算的所谓的网页重要性是什么，仅仅只是知道网页有这样一个属性。这里我们要清楚网页的超链接结构之中蕴含了重要程度的信息，类似于投票，一个网页被许多超链接链入，其重要性也就相应越高。同时，对于不同的用户，不同的网页具有不同的重要性，比方说，数码产品爱好者和果农，“苹果”指代着不同的事物，他们所希望搜索到的网页也不同。也就是说，苹果公司官网，中国种子网站对于他们两个的重要性是不同的。在最理想的情况下，我们应该为每一名用户量身定制一套专用的重要性初始向量，显然是不可能的，因此就有了Topic-Sensitive PageRank。

在上述的迭代公式中
$$
X'=aMX+(1-a)X_0
$$
$X_0$就是所谓的重要性初始向量，其中的元素都是$1/n$，即初始等重要性，那么最后的Rank值全部都由超链接来传递，无法体现用户的个人倾向。

这里Topic-Sensitive PageRank的做法是预先定义话题类别，例如数码产品、娱乐音乐、教育等等，同时为各个话题设置一个向量，接着搜集用户信息，关联用户话题倾向，再根据其倾向排序结果。

因此我们新的迭代公式如下：
$$
X^{\prime}=(1-\alpha) M X+S \frac{\alpha}{|S|}
$$
$S$向量的构成按照以下规定：如果某网站属于所搜索的话题，则该网站相对应的位置置$1$，再除以$|S|$就是比例化。

而获取用户倾向就很简单了，只需要列出你所划定的话题让用户去选就好了。

## 想法与实践

在对PageRank算法的进一步了解之后，我觉得它可以使用在一些特定的场景：

1. 问题需要多维度考量，需要对选择对象多方面进行评估（为满足这种情况，我认为迭代使用的未必是向量，可以是矩阵，这样更能体现个体的各方面评估，相应的，最后得到收敛值之后，需要有综合公式）。
2. 选择对象间存在联系，这里联系应具有影响最终选择结果的特点。

### 领袖选举

在一个团队项目中，我们不免需要推选出一名队长，这里为保证民主性、公平性、选举结果合理性，我们需要综合考虑每一个人的各方面素质，以及每一个人的意见，相对应地我认为我们可以套用PageRank的模型来解决这个问题。

首先，每一个人做自我评价，对各方面素质进行评估，利用一些领导能力评估的公式来计算每一个人的成为领袖的初值$x'_j$，再进行概率化，即初始向量$X_0=[x_j]^T$满足所有$\sum x_j=1$，其中每一项的大小都取决于初值$x'_j$的大小，即个人是否具备足够的领导力。

接着，每个人根据一些方法，如调查问卷、民主投票等，对他人进行评估，再用一些统计学公式将其转化为评价指数或推荐指数，进而构造转移矩阵，即
$$
M^T=\left[ y_{ij}\right]
$$

 其中$y_{ij}$指第$i$个人对第$j$个人的评价指数或推荐指数。

因此，使用迭代公式
$$
X'=(1-\alpha)MX+\alpha X_0
$$
对组内人员进行排序（其中$\alpha$是自身能力占比），从而获得领袖能力与民意期望综合最高的领袖。

#### C语言代码模拟

- **data.txt文件**

```c
6
//（6人组内推选）
0.30 0.10 0.13 0.12 0.15 0.20
//（6人个人能力测评）

0.25 0.10 0.05 0.40 0.25 0.10
0.55 0.20 0.05 0.30 0.00 0.15
0.05 0.12 0.13 0.15 0.05 0.15
0.05 0.18 0.20 0.10 0.20 0.25
0.05 0.20 0.22 0.05 0.40 0.30
0.05 0.20 0.35 0.00 0.10 0.05
//（民主投票矩阵（已转置））
```
- **Rank.c文件**

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define epsilon 0.0000001 //近似精度
#define MAXIterations 30  //迭代最大数量
#define Stop 0
#define Go 1
#define alpha 0.8 //自我能力占比

int IsConvergent(const int dim, float *new, float *last) //判断是否收敛
{
    int i;
    float diff = 0;
    for (i = 0; i < dim; ++i)
        diff += fabsf(*(new) - *(last));
    diff /= dim;
    if (diff <= epsilon)
        return Stop;
    else
        return Go;
}

void MatrixMultiVecter(float **matrix, float *vector, float *last, float *ori, const int dim)
{
    int countrow, countcol;
    for (countrow = 0; countrow < dim; ++countrow)
    {
        float sum = 0;
        for (countcol = 0; countcol < dim; ++countcol)
            sum += (1 - alpha) * (*(*(matrix + countrow) + countcol)) * (*(vector + countcol)); //迭代方程
        *(last + countrow) = sum;
        *(last + countrow) += alpha * (*(ori + countrow));
    }
}

int main(void)
{
    int dim, i, j;
    FILE *data = freopen("data.txt", "r", stdin); //读取数据
    if (data == NULL)
        exit(-1);
    scanf("%d", &dim);

    float *ori = (float *)malloc(dim * sizeof(float));
    float *vector = (float *)malloc(dim * sizeof(float));
    float **matrix = (float **)malloc(dim * sizeof(float *));
    for (i = 0; i < dim; ++i)
        *(matrix + i) = (float *)malloc(dim * sizeof(float));

    for (i = 0; i < dim; ++i)
    {
        scanf("%f", (vector + i));
        *(ori + i) = *(vector + i);
    }
    for (i = 0; i < dim; ++i)
        for (j = 0; j < dim; ++j)
            scanf("%f", *(matrix + i) + j);

    int times = 1;
    float *last = (float *)malloc(dim * sizeof(float));
    MatrixMultiVecter(matrix, vector, last, ori, dim);
    while (IsConvergent(dim, vector, last) == Go && times <= MAXIterations) //跳出条件有二，收敛，迭代次数超过上限
    {
        memcpy(vector, last, sizeof(float) * dim);
        MatrixMultiVecter(matrix, vector, last, ori, dim);
        ++times;
    }

    for (i = 0; i < dim; ++i)
            printf("%f ", *(vector + i));
        printf("\n");

    fclose(data);
    return 0;
}
```

- **运行结果**

```c
0.279476 0.130224 0.123968 0.126384 0.158285 0.181664
```
