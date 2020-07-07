- 康托展开是一个全排列到一个自然数的双射，常用于构建hash表时的空间压缩。

- 设有$n$个数$(1，2，3，4,…,n)$，可以有组成不同($n!$种)的排列，康托展开表示的就是是当前排列组合在n个不同元素的全排列中的名次。

  $X = a[n] * (n - 1)!+a[n - 1] * (n - 2)!+...+a[i] * (i - 1)!+...+a[1] * 0! $

- 其中，$a[i]$为整数，并且$0 <= a[i] <= i, 0 <= i < n, $表示当前未出现的的元素中排第几个，这就是康托展开。

- 注：

  - 名次是从小到大排序，且从零计数。
  - 这个阶乘得提前算或者直接给出`int FAC[N] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};`

- 例：
  对于数组：$1\ 2\ 3\ 4\ 5\ 6\ 7\ 8\ 9$，其中的一种排列：$8\ 6\ 9\ 1\ 4\ 5\ 2\ 3\ 7$，各个数位后面比他小的值,即运算式中的权值$a[n]$有：$7 5 6 0 2 2 0 0 0$，则他的的名次为：$7 * 8! + 5 * 7! + 6 * 6! + 2 * 4! + 2 * 3! + 1 = 311820 + 1$

- 逆康托展开就是上式的逆运算，从高到低除$i!$，储存商，获得权值数列，再利用权值数列反求排列。

```c
int FAC[N] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int ORG[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int CantorExpansion(int num[], int n)
{
    int rank = 0, count, i, j;
    for (i = 0; i < n - 1; ++i)
    {
        count = 0;
        for (j = i + 1; j < n; ++j)
            if (*(num + j) < *(num + i))
                count++;
        rank += FAC[n - 1 - i] * count;
    }
    return ++rank;
}

int *CantorExpansionReverse(int rank, int org[], int n)
{
    int *result = (int *)malloc(sizeof(int) * n);
    int i, j, count;
    rank--;
    for (i = n - 1; i >= 0; --i)
    {
        result[n - 1 - i] = rank / FAC[i];
        for (j = 0, count = 0; count != result[n - 1 - i] && j < N; ++j)
            if (org[j] > 0)
                count++;
        while (org[j] < 0)
            j++;
        result[n - 1 - i] = org[j];
        org[j] = -1;
        rank %= FAC[i];
    }
    return result;
}
```



