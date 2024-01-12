// QUESTÃO 1
/*
#include <stdio.h>

void reverseArrayUsingArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void reverseArrayUsingPointer(int *arr, int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = *(arr + i);
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    // Test of the function with an array
    printf("Original array: ");
    printArray(array, size);

    reverseArrayUsingArray(array, size);

    printf("Reversed array (using array): ");
    printArray(array, size);

    // Test of the function with a pointer
    printf("Original array: ");
    printArray(array, size);

    reverseArrayUsingPointer(array, size);

    printf("Reversed array (using pointer): ");
    printArray(array, size);

    return 0;
}
*/


// QUESTÃO 2
/*
#include <stdio.h>
#include <stdlib.h>

int* multiplyElementsByIndexArray(int arr[], int size) {
    int* result = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        result[i] = arr[i] * i;
    }

    return result;
}

int* multiplyElementsByIndexPointer(int *arr, int size) {
    int* result = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        result[i] = *(arr + i) * i;
    }

    return result;
}

void printCollection(int* collection, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", collection[i]);
    }
    printf("\n");
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Test of the function with an array
    printf("Original array: ");
    printCollection(numbers, size);

    int* resultArray = multiplyElementsByIndexArray(numbers, size);

    printf("Collection (using array): ");
    printCollection(resultArray, size);

    free(resultArray);

    // Test of the function with a pointer
    printf("Original array: ");
    printCollection(numbers, size);

    int* resultPointer = multiplyElementsByIndexPointer(numbers, size);

    printf("Collection (using pointer): ");
    printCollection(resultPointer, size);

    free(resultPointer);

    return 0;
}
*/


// QUESTÃO 7
#include <stdio.h>

const int ROWS = 8;
const int COLUMNS = 8;

int rookMovement(int origin[], int destination[]) {
    for (int i = 0; i < 2; i++) {
        if (origin[i] < 0 || origin[i] >= ROWS || destination[i] < 0 || destination[i] >= ROWS) {
            return 0;
        }
    }

    if (origin[0] == destination[0] || origin[1] == destination[1]) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int origin1[] = {0, 0};
    int destination1[] = {0, 7};
    int origin2[] = {2, 3};
    int destination2[] = {5, 6};
    
    printf("%s\n", rookMovement(origin1, destination1) ? "True" : "False");
    printf("%s\n", rookMovement(origin2, destination2) ? "True" : "False");

    return 0;
}