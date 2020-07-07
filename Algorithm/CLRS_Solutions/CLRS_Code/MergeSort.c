#include <stdio.h>
#include <stdlib.h>

void showArray(int arr[], int length)
{
    int i;
    for (i = 0; i < length; ++i)
        printf("%d ", arr[i]);
    putchar('\n');
}

#define INF 0x7FFFFFFF
void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m, i;
    int L[len1 + 1], R[len2 + 1];
    for (i = 0; i < len1; ++i)
        L[i] = arr[l + i];
    for (i = 0; i < len2; ++i)
        R[i] = arr[m + 1 + i];
    L[len1] = R[len2] = INF; //set boundary but there will be extra comparisons
    int p = 0, q = 0;
    for (i = l; i <= r; ++i)
    {
        if (L[p] <= R[q])
            arr[i] = L[p++];
        else
            arr[i] = R[q++];
    }
}

void mergeSort1(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + ((r - l) >> 1);
        mergeSort1(arr, l, mid);
        mergeSort1(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void mergeSort2(int arr[], int l, int r)
{
    int m = l + ((r - l) >> 1);

    if (l < r)
    {
        mergeSort2(arr, l, m);
        mergeSort2(arr, m + 1, r);
    }

    int len1 = m - l + 1, len2 = r - m, i;
    int L[len1], R[len2];
    for (i = 0; i < len1; ++i)
        L[i] = arr[l + i];
    for (i = 0; i < len2; ++i)
        R[i] = arr[m + 1 + i];
    i = 0;
    int k = l, j = 0;
    while (i < len1 && j < len2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < len1)
        arr[k++] = L[i++];
    while (j < len2)
        arr[k++] = R[j++];
}

int main(void)
{

    int array1[] = {5, 2, 4, 6, 1, 3};
    int length1 = sizeof(array1) / sizeof(*array1);

    showArray(array1, length1);
    mergeSort1(array1, 0, length1 - 1);
    showArray(array1, length1);

    int array2[] = {5, 2, 4, 6, 1, 3};
    int length2 = sizeof(array2) / sizeof(*array2);

    showArray(array2, length2);
    mergeSort2(array2, 0, length2 - 1);
    showArray(array2, length2);
    return 0;
}