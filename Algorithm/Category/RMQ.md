# Range Minimum/Maximum Query

## 问题描述

> 对于长度为`n`的数列`A`，回答若干询问`RMQ(A,i,j)` `(i,j<=n)`，返回数列`A`中下标在`i`,`j`里的最小（大）值。

也就是查询给定区间的最值问题。

## 解决方法1------ST(Space-Table)表

ST表是一种基于倍增思想并通过动态规划实现的算法。

用$dp(i,j)$表示从第$i$开始的长度为$2^j$的一段元素中的最小值（$ArraySize=n$），则有以下状态转移方程
$$
dp(i,j)=\max[dp(i,j-1),dp(i+2^{j-1},j-1)]
\\
dp(i,0)=Array[i]
,2^j<n
$$
因此$dp$数组的大小将不超过$nlogn$，故预处理时间为$O(nlogn)$，而查询时间$O(1)$。

```c++
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>

#define MAX_EXPONENT 11 //2 ^ 10=  1024 > 1000
#define MAX_SIZE 1000
#define BIG 0x3f3f3f3f
#define SMALL -0x3f3f3f3f

int32_t max(int32_t x, int32_t y);
int32_t min(int32_t x, int32_t y);

int32_t array[MAX_SIZE];
int32_t dp_max[MAX_SIZE][MAX_EXPONENT];
int32_t dp_min[MAX_SIZE][MAX_EXPONENT];
static int32_t log2Val[MAX_SIZE];

inline int32_t max(int32_t x, int32_t y) { return x > y ? x : y; };
inline int32_t min(int32_t x, int32_t y) { return x < y ? x : y; };

void PreGetLogVal(void)
{
    log2Val[0] = -1;
    log2Val[1] = 0;
    int i;
    for (i = 2; i < MAX_SIZE; ++i)
        log2Val[i] = log2Val[i >> 1] + 1;
}

int main(void)
{
    size_t N, i, j;
    size_t qLeft, qRight, intervalLen;

    PreGetLogVal();
    memset(dp_min, BIG, sizeof(dp_min));
    memset(dp_max, SMALL, sizeof(dp_max));

    scanf("%u", &N);
    for (i = 1; i <= N; ++i)
    {
        scanf("%d", array + i);
        dp_max[i][0] = dp_min[i][0] = array[i];
    }
    size_t log2NCeil = ceil(log2(N));

    for (j = 1; j < log2NCeil; ++j)
        for (i = 1; i + (1 << (j - 1)) <= N + 1; ++i)
        {
            dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << (j - 1))][j - 1]);
            dp_min[i][j] = min(dp_min[i][j - 1], dp_min[i + (1 << (j - 1))][j - 1]);
        }

    for (i = 1; i <= N; ++i)
        for (j = 0; j < log2NCeil; ++j)
            printf("dp_max[%u][%u] = %d\n", i, j, dp_max[i][j]);
    putchar('\n');

    for (i = 1; i <= N; ++i)
        for (j = 0; j < log2NCeil; ++j)
            printf("dp_min[%u][%u] = %d\n", i, j, dp_min[i][j]);
    putchar('\n');

    while (scanf("%u %u", &qLeft, &qRight) == 2)
    {
        intervalLen = log2Val[qRight - qLeft + 1];
        printf("%d %d\n",
               max(dp_max[qLeft][intervalLen],
                   dp_max[qRight - (1 << (intervalLen - 1))][intervalLen]),
               min(dp_min[qLeft][intervalLen],
                   dp_min[qRight - (1 << (intervalLen - 1))][intervalLen]));
    }

    return 0;
}
```

