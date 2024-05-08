#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//questão 4.1:
    void troca(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void bubbleSort(int V[], int n) {
        int i, j;
        int trocou = -1;
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (V[j] > V[j+1]) {
                    troca(&V[j], &V[j+1]);
                    trocou = 1;
                }
            }
            if (trocou == -1) break;
        }
    }

    main() {
        const int N = 9;
        int i, V[N] = {6, 2, 1, 3, 4, 5, 8, 7, 0};
        bubbleSort(V, N);
        
        for(i = 0; i < N; i++) 
            printf("%d\n", V[i]);
        getch();
    }
*/


//questão 4.2:
    int troca(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void quickSort(int V[], int esq, int dir) {
        int i, j, P;
        int trocou = 0;
        do {
            P = (esq+dir) / 2;
            for (i = esq; V[i] < V[P]; i++);
            for (j = dir; V[j] > V[P]; j--);
            if (i < j) trocou = troca(&V[i], &V[j]);
        } while (trocou);

        if (P > esq) 
            quickSort(V, esq, P);
        if (P+1 < dir) 
            quickSort(V, P+1, dir);
    }

    main() {
        const int N = 9;
        int i, V[N] = {6, 2, 1, 3, 4, 5, 8, 7, 0};
        quickSort(V, 0, N-1);
        
        for(i = 0; i < N; i++) 
            printf("%d\n", V[i]);
        getch();
    }


//questão 4.3:
void unir(int V[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int E[n1], D[n2]; //arrays temporários

    //cópia de V para os arrays temporários
    for (i = 0; i < n1; i++)
        E[i] = V[esq + 1];
    for (j = 0; j < n2; j++)
        D[J] = V[meio + 1 + j];
    
    //une os arrays temporários com V
    i = 0; j = 0; k = esq;
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            V[k] = E[i];
            i++;
        } else {
            V[k] = D[j];
            j++;
        }
        k++;
    }

    //copia os demais elementos de E e D para V
    while (i < n1) {
        V[k] = E[i];
        i++; k++;
    }

    while (j < n2) {
        V[k] = D[j];
        j++; k++;
    }
}

void mergeSort(int V[], int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + (dir-1)) / 2;
        mergeSort(V, esq, meio);
        mergeSort(V, meio+1, dir);
        merge(V, esq, meio, dir);
    }
}

main() {
    const int N = 5;
    int i, V[N] = {8,4,3,7,9};
    int V_size = sizeof(V) / sizeof(V[0]);
    mergeSort(V, 0, V_size - 1);

    for(i = 0; i < N; i++)
        printf("%d\n", V[i]);
    getch();
}