#include <stdio.h>
#include <stdlib.h>

int array[] = {5, 2, 4, 6, 1, 3};
int length = sizeof(array) / sizeof(*array);
void showArray(int arr[], int length)
{
    int i;
    for (i = 0; i < length; ++i)
        printf("%d ", arr[i]);
    putchar('\n');
}

void insertionSort(int arr[], int length)
{
    int j;
    for (j = 1; j < length; ++j)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) //asending
        {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}

int main(void)
{
    showArray(array, length);
    insertionSort(array, length);
    showArray(array, length);
    return 0;
}