// [L4] questão 4.2:
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int arr[], int left, int right)
{
    int i, j, pivot;
    int swapped = 0;
    do
    {
        pivot = (left + right) / 2;
        for (i = left; arr[i] < arr[pivot]; i++)
            ;
        for (j = right; arr[j] > arr[pivot]; j--)
            ;
        if (i < j)
            swapped = swap(&arr[i], &arr[j]);
    } while (swapped);

    if (pivot > left)
        quickSort(arr, left, pivot);
    if (pivot + 1 < right)
        quickSort(arr, pivot + 1, right);
}

int main()
{
    const int N = 9;
    int i, arr[N] = {6, 2, 1, 3, 4, 5, 8, 7, 0};
    quickSort(arr, 0, N - 1);

    for (i = 0; i < N; i++)
        printf("%d\n", arr[i]);
    getch();
}