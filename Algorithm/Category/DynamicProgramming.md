# Dynamic Programming

## Concept

动态规划是运筹学中用于求**解决策过程中的最优化数学方法**。 当然，我们在这里关注的是作为一种算法设计技术，作为一种使用**多阶段决策(multi-stage decision processes)**过程最优的通用方法。它是应用数学中用于解决某类最优化问题的重要工具。

### **Definition** 

> *Dynamic programming is a method for solving complex problems by breaking them down into simpler subproblems*

动态规划的本质是对问题(这里的"问题"和下面的"问题"不是同一个意思，我偏向于称此"问题"为"题目")**状态的定义**和**状态转移方程的定义**。

### **State**

在动态规划算法中，状态是对某一时刻或者时间下某一递归量的准确描述，这里我们通常会将**状态**又称为**问题**，因为要进行递归，所以对应的更小的**问题**，被称为**子问题**。

### Recurrence Equation

描述问题与子问题之间的关系，带有边界条件（或称初值条件）的递推式。

注意，动态规划是对于**某一类**问题的解决方法，我们所要关注的重点是该问题**是否动态规划可解**，而不是去纠结解的形式。

### Comparison

每个阶段只有一个状态->递推；

每个阶段的最优状态都是由上一个阶段的最优状态得到的->贪心；

每个阶段的最优状态是由之前所有阶段的状态的组合得到的->搜索；

每个阶段的最优状态可以从之前某个阶段的某个或某些状态直接得到而不管之前这个状态是如何得到的->动态规划。

每个阶段的最优状态可以从之前某个阶段的某个或某些状态直接得到，这个性质叫做最优子结构；而不管之前这个状态是如何得到的，这个性质叫做无后效性。

### Multi-stage Decision Processes

在生产经营活动中，某些问题决策过程可以划分为若干相互联系的阶段，每个阶段需要做出决策，从而使整个过程取得最优。由于各个阶段**不是孤立的，而是有机联系的**，也就是说，本阶段的决策将影响下一阶段的发展，从而影响整个过程效果，所以决策者在进行决策时不能够仅考虑选择的决策方案使本阶段最优，还应该考虑本阶段决策对最终目标产生的影响，从而做出对全局来讲是最优的决策。

## Steps

1. Define subproblems
2. Write down the recurrence that relates subproblems
3. Recognize and solve the base cases

## Method

### 重新审视斐波那契数列

我们先从最简单的斐波那契数列的计算开始，当然它有很多种计算方法，这里我们采取具有动态规划思想的几种。

斐波那契数列定义如下，很明显这就是我们的状态转移方程。
$$
F_{n}=\begin{cases}1\left( n=0,1\right) \\ F_{n-1}+F_{n-2}\left( n\geq 2\right) \end{cases}
$$
以下是我们最初学习递归时的一个经典递归样例。
```c
/*简单的递归实现 */
int FibonacciEasyRecursion(int n)
{
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
    else
        return FibonacciEasyRecursion(n - 1) + FibonacciEasyRecursion(n - 2);
}
```
因为是双重递归，而且递归都会进行到底，从递归树来看，叶上全是重复计算的值，比如当我们计算$F_6$时，$F_2$会被重复计算$5$次，那我们能不能将计算过后的$F_2 $存储起来，当下一次需要的时候就拿来用？见下方改进过后的含备忘录递归。显然，当我们需要计算$F_n$时，从$F_2 $至$F_{n-1}$都只计算了一次，耗时为$O(n)$，空间占用也是$O(n)$。
```c
/*含备忘录递归实现 */
int MemoRecursion(int n, int *memo)
{
    if (memo[n] != -1)
        return memo[n];
    else if (n <= 1)
        return memo[n] = 1;
    else
        return memo[n] = MemoRecursion(n - 1, memo) + MemoRecursion(n - 2, memo);
}
int FibonacciMemoryRecursion(int n)
{
    if (n < 0) return 0;
    int *memo = (int *)malloc(sizeof(int) * (n + 1));//建立备忘录
    memset(memo, -1, sizeof(int) * (n + 1));
    int ans = FibonacciMemoRecursion(n, memo);
    free(memo);
    return ans;
}
```
考虑到在整个的过程中只有一个状态，即状态转移方程中，右侧各子问题系数均为$1$，这说明递推可以很简单地解决问题。

```c
/*自底向上递推实现*/
int FibonacciDownToTop(int n)
{
    if (n <= 1)
        return 1;
    int i;
    int F0 = 1, F1 = 1, Fn = F0 + F1;
    for (i = 3; i <= n; i++)
    {
        F1 = F0;
        F0 = Fn;
        Fn = F0 + F1;
    }
    return Fn;
}
```

## Examples and Templates

### 1-dimensional DP

> Maximum Sum of Subarray
>
> Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
>
> Example:
>```
> Input: [-2,1,-3,4,-1,2,1,-5,4],
> Output: 6
> Explanation: [4,-1,2,1] has the largest sum = 6.
> ```

> DescriptionIn how many ways can you tile a $3\times n$ rectangle with $2 \times 1$ dominoes? Here is a sample tiling of a $3 \times 12$ rectangle. 
>
> ![](./img/DP.gif)
>
> Input consists of several test cases followed by a line containing $-1$. Each test case is a line  containing an integer $0 \le n \le 30$.
>
> For each test case, output one integer number giving the number of possible tilings.
>
> Sample Input
> ```
> 2
> 8
> 12
> -1
> ```
> Sample Output
> ```
> 3
> 153
> 2131
> ```

### 2-dimensional DP

> Longest Common Subsequence Problem
>
> Let us think of character strings as sequences of characters. Given two sequences $X=\langle x_1,x_2,\dots,x_n\rangle$ and $Z=\langle z_{1}, z_{2}, \dots, z_{k}\rangle$, we say that $Z$ is a subsequence of $X$ if there is a strictly increasing sequence of $k$ indices $\left\langle i_{1}, i_{2}, \ldots, i_{k}\right\rangle\left(1 \leq i_{1}<i_{2}<\ldots<i_{k} \leq n\right)$ such that $Z=\left\langle X_{i_{1}}, X_{i_{2}}, \dots, X_{i_{k}}\right\rangle$. For example, let $X=\langle A B R A C A D A B R A\rangle$ and let $Z=\langle A A D A\rangle$, then $Z$ is a subsequence of $X$.
>
> Given two strings $X$ and $Y$, the longest commom subsequence of $X$ and $Y$ is a longgest sequence $Z$ which is both a subsequence of $X$ and $Y$.
>
> For example, let $X$ be as before and let $Y=\langle Y A B B A D A B B A D O O \rangle$ . Then the longest commom subsequence is $Z=\langle ABADABA\rangle$.
>
> The Longest Common Subsequence Problem（LCS） is the following. Given two sequences $X=\langle x_1,x_2,\dots,x_m\rangle$  and $Y=\langle y_1,y_2,\dots,y_n\rangle$ determine a longest common subsequence. Note that it is not always unique. For example the LCS of $\langle ABC\rangle$ and $\langle BAC\rangle$ is either $\langle A C\rangle$ or $\langle B C\rangle$.

### Interval DP

> Levenshtein distance---**edit distance**
>
> 莱文斯坦距离(Levenshtein distance)是编辑距离的一种。它由俄罗斯科学家 弗拉基米尔·莱文斯坦在1965年提出。两个字符串之间的莱文斯坦距离是将一个单词更改为另一个单词所需的最少编辑操作次数。莱文斯坦距离允许的编辑操作包括单个字符的**替换/插入/删除**。
>
> 例如：“Saturday” 和 “Sundays” 之间的 Levenshtein 距离是 4
>
> ```
> 1.)  Saturday → Sturday  // 删除第一个 a
> 2.)  Sturday  → Surday   // 删除第一个 t
> 3.)  Surday   → Sunday   // 替换 r 为 n
> 4.)  Sunday   → Sundays  // 结尾添加 s
> ```
>
> - 无操作
>
> - 计算 "ay" 和 "day" 之间的莱文斯坦距离。
>
> 对于两个字符串的最后一位字符 “y”，我们可以选择不操作，也就是说，
> “ay” 和 “day” 之间的莱文斯坦距离等于 “a” 和 “da” 之间的莱文斯坦距离。
>
> - 替换操作
>
> - 计算 "dae" 和 "day" 之间的莱文斯坦距离。
>
> 对于两个字符串的最后一位字符 “e” 和 “y”，我们可以选择对最后一位字符进行替换操作，也就是说
> “dae” 和 “day” 之间的莱文斯坦距离等于 “da” 和 “da” 之间的莱文斯坦距离加上 1。
>
> - 插入操作
>
> - 计算 "dae" 和 "da" 之间的莱文斯坦距离。
>
> 对于两个字符串的最后一位字符 “e” 和 “a”，我们可以选择在 “da” 后进行插入操作，也就是说
> “dae” 和 “da” 之间的莱文斯坦距离等于 “da” 和 “da” 之间的莱文斯坦距离加上 1。
>
> - 删除操作
>
> - 计算 "dae" 和 "daey" 之间的莱文斯坦距离。
>
> 对于两个字符串的最后一位字符 “e” 和 “y”，我们可以选择在 “daey” 后进行删除操作，也就是说
> “dae” 和 “daey” 之间的莱文斯坦距离等于 “dae” 和 “dae” 之间的莱文斯坦距离加上 1。

状态转移方程

```c
if (word1[i-1] == word2[j-1])
    dp[i][j] = dp[i - 1][j - 1];
else
    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
```

### Bag Problem

#### 0-1 背包

> 给定$n$种物品和一个容量为$C$的背包，物品$i$的重量是$w_i$，其价值为$v_i$，该如何选择装入背包的物品，使得装入背包中的物品的总价值最大？

分析一波，面对每个物品，我们只有选择拿取或者不拿两种选择，不能选择装入某物品的一部分，也不能装入同一物品多次。

解决办法：声明一个 大小为` m[n][c]`的二维数组，`m[i][j]`表示 在面对第` i `件物品，且背包容量为` j `时所能获得的最大价值 ，那么我们可以很容易分析得出` m[i][j] `的计算方法:

1. `j < w[i]` 的情况，这时候背包容量不足以放下第` i `件物品，只能选择不拿`m[i][j] = m[i-1][j]`

2. `j >= w[i]` 的情况，这时背包容量可以放下第` i `件物品，我们就要考虑拿这件物品是否能获取更大的价值。

如果拿取，`m[i][j]=m[i-1][j-w[i]] + v[i]`。 这里的`m[i-1][j-w[i]]`指的就是考虑了`i-1`件物品，背包容量为` j-w[i] `时的最大价值，也是相当于为第 i 件物品腾出了w[i]的空间。如果不拿，`m[i][j] = m[i-1][j] `, 同1.，究竟是拿还是不拿，自然是比较这两种情况那种价值最大。由此可以得到状态转移方程：

```c
if(j >= w[i])
	m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
else
	m[i][j]=m[i-1][j];
```

#### 完全背包

> 有编号分别为a,b,c,d的四件物品，它们的重量分别是2,3,4,7，它们的价值分别是1,3,5,9，每件物品数量**无限**个，现在给你个承重为10的背包，如何让背包里装入的物品具有最大的价值总和？
>
> 类比01背包问题我们可以得到新的递推式：
> $$
> map[i][j] = max\{map[i - 1][j - k * weight[i]] + k * value[i]\ |\ 0 <= k * weight[i] <= j\}
> $$
>

#### 多重背包

>有$N$种物品和容量为$V$的背包，若第$i$种物品，质量为$v_{i}$，价值为$w_{i}$，共有$n_{i}$件。怎样装才能使背包内的物品总价值最大？
>
>多重背包转换成01背包问题仅仅多了个初始化，把它的件数C用二进制分解成若干个件数的集合，这里面数字可以组合成任意小于等于$C$的件数，而且不会重复，之所以叫二进制分解，是因为这样分解可以用数字的二进制形式来解释
>
>比如：$7$的二进制$ 7 = 111 $它可以分解成$ 001\ 010\ 100 $这三个数可以组合成任意小于等于$7 $的数，而且每种组合都会得到不同的数。又如$13 = 1101 $，则可分解为$ 0001\ 0010\ 0100\ 0110 $前三个数字可以组合成7以内任意一个数，即$1、2、4$可以组合为$1-7 $内所有的数，加上$ 0110 = 6 $可以组合成任意一个大于$6 $小于等于$13$的数，比如$12$，可以让前面贡献$6$且后面也贡献$6$就行了。虽然有重复但总是能把$ 13 $以内所有的数都考虑到了，基于这种思想去把多件物品转换为，多种一件物品，就可用01背包求解了。
>
>**定理：**一个正整数$n$可以被分解成$1,2,4,…,2^{(k-1)},n-2^k+1$（$k$是满足$n-2^k+1>0$的最大整数）的形式，且$1～n$之内的所有整数均可以唯一表示成$1,2,4,…,2^{(k-1)},n-2^k+1$中某几个数的和的形式。
>
>证明如下：
>
>1. 数列$1,2,4,…,2^{(k-1)},n-2^k+1$中所有元素的和为$n$，所以若干元素的和的范围为$[1, n]$；
>
>2. 如果正整数$t\le 2^k – 1$,则$t$一定能用$1,2,4,…,2^{(k-1)}$中某几个数的和表示，这个很容易证明：我们把$t$的二进制表示写出来，很明显，$t$可以表示成$n=a_0*2^0+a_1*2^1+…+a_k*2^{(k-1)}$，其中$a_k=0$或者$1$，表示$t$的第$a_k$位二进制数为$0$或者$1$.
>
>3. 如果$2^k \le t \le n$,设$s=n-2^k+1$，则$t-s<=2^k-1$，因而$t-s$可以表示成$1,2,4,…,2^{(k-1)}$中某几个数的和的形式，进而$t$可以表示成$1,2,4,…,2^{(k-1)}$，$s$中某几个数的和（加数中一定含有$s$）的形式。
>
>   （证毕！）

### Tree DP

>树形DP主要实现形式是DFS，即`dp[i][j][0/1]`，`i`指以`i`为根的子树，`j`是表示在以`i`为根的子树中选择`j`个子节点，`1`和`0`分别表示这个节点选或不选，有时最后一维的`[0/1]`可以压缩掉。
>
>树形数据结构构造需求：左儿子右兄弟法
>
>状态转移方程不固定，一道题一种解。

