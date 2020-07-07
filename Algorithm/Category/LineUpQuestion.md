# 站队问题

## 问题描述

> 在坐标系下有$n$个点，已知其坐标为$(x_1,y_1),(x_2,y_2),\ldots,(x_n,y_n)$，现将这些点移动到一条平行于$x$轴的直线上，同时连续排列，要求所有点移动的曼哈顿距离之和最短，并求出。以上所涉及的均为整数。

## 问题分析

易知，沿两个坐标轴方向上的移动距离和互不干扰，因此以下分两部分分别求最小值：

- 考虑$y$轴方向上的距离和，设最终直线纵坐标为$y$，则有如下$y$轴方向距离和
  $$
  D(y)=|y_1-y|+|y_2-y|+\cdots +|y_n-y|
  $$
  根据绝对值函数的性质，以上函数的最值将在中间形成的“平台”处取得，即$y_1,y_2,\dots,y_n$这列数的中位数处（对于奇数个来说）或中间两个数间（对于偶数个来说）取得。所以这里求取中位数即可。

- 考虑$x$轴方向上的距离和，设最终线段所在区间为$[k,k+n-1]$，则有以下距离函数，其中要求$x_1,x_2,\ldots,x_n$递增。
  $$
  D(k)=|x_1-k|+|x_2-(k+1)|+\cdots+|x_n-(k+n-1)|
  $$
  变形一下
  $$
  D(k)=|x_1-k|+|(x_2-1)-k|+\cdots+|[x_n-(n-1)]-k|
  $$
  所以同上，求$x_1,x_2-1,\cdots,x_n-n+1$的中位数即可。

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int cmp(const void *a, const void *b)
{
    return *(long long *)a - *(long long *)b;
}

int main(void)
{
    long long int sum = 0;
    long long int x[MAX_SIZE], y[MAX_SIZE], xmid, ymid;

    unsigned int i, n;
    scanf("%u", &n);
    for (i = 0; i < n; ++i)
        scanf("%lld %lld", x + i, y + i);

    qsort(x, n, sizeof(x[0]), cmp);
    qsort(y, n, sizeof(y[0]), cmp);

    for (i = 0; i < n; ++i)
        *(x + i) -= i;

    qsort(x, n, sizeof(x[0]), cmp);

    xmid = x[(n - 1) / 2];
    ymid = y[(n - 1) / 2];

    for (i = 0; i < n; ++i)
        sum += llabs(x[i] - xmid) + llabs(y[i] - ymid);

    printf("%lld\n", sum);

    return 0;
}
```

## 中位数算法

1. 先排序再求取，$O(nlogn)$。
2. 对快排的划分进行变形，仅求数列中第$n/2$大的数，$O(n) $。