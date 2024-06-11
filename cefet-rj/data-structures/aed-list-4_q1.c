// [L4] questão 4.1:
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    int swapped = -1;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == -1)
            break;
    }
}

int main()
{
    const int N = 9;
    int i, arr[N] = {6, 2, 1, 3, 4, 5, 8, 7, 0};
    bubbleSort(arr, N);

    for (i = 0; i < N; i++)
        printf("%d\n", arr[i]);
    getch();
}