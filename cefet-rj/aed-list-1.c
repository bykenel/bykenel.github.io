#include <stdio.h>
#include <stdlib.h>

/*[L1] questao 1:
    i. falso: depende do argumento que é passado à função.
    ii. verdadeiro
    */

// [L1] questão 1.2:
int factorial(int x)
{
    int fat = 1;
    for (int i = 1; i <= x; i++)
    {
        fat = fat * i;
    }
    return fat;
}

/*[L1] questão 1.3:
    O algoritmo executa 1 movimento de disco e dá início a outras 2 versões de seu processo para um valor de n imediatamente inferior. Portanto, a expressão que define essa quantidade é dada por 2^n-1.
    */

// [L1] questão 1.4:
void move(int n, char A, char B)
{
    printf("\n Move disk %d from rod %c to rod %c", n, A, B);
}

void towerOfHanoi(int n, char A, char B, char C)
{
    if (n == 1)
        move(n, A, B);
    else
    {
        towerOfHanoi(n - 1, A, C, B);
        move(n, A, B);
        towerOfHanoi(n - 1, C, B, A);
    }
}

/*A execução de n=0 será desconsiderada dessa forma mas a complexidade se manterá a mesma O(2^n).

    if (n > 0) {
        towerOfHanoi(n - 1, A, C, B);
        move(n, A, B);
        towerOfHanoi(n - 1, C, B, A);
    } -> com 3 discos: 15x - O(2^n)

    if (n >= 1) {
        towerOfHanoi(n - 1, A, C, B);
        move(n, A, B);
        towerOfHanoi(n - 1, C, B, A);
    } -> com 3 discos: 15x - O(2^n)
*/

/*[L1] questão 1.5:
        i. O(n^3)
        ii. O(n^2)
        iii. O(n^n)
        iv. O(n^n)
        v. O(1)
    */

// [L1] questão 1.6:
int fibonacci(int f[], int n)
{
    int f[0] = 0;
    int f[1] = 1;

    for (int i = 2; i < n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        return f[n - 1];
    }
}

// [L1] questão 1.7:
int g(int f[], int n, int k)
{
    if (k > 1)
        for (int i = 0; i < n; i++)
        {
            if (i < k)
                f[i] = i;
            else
                f[i] = f[i - 1] + f[i - 2];
            return f[i];
        }
}

/*[L1] questão 1.8:
    a. O(n), uma vez que todos os n valores do vetor são percorridos.
    b. Na primeira vez, serão realizadas n-1 comparações no vetor; na segunda, n-2 comparações; ... ; na última, 1 comparação. A quantidade total de comparações é dada por (n-1) + (n-2) + (n-3) + ... + 3 + 2 + 1.
       Esta expressão é a soma de uma PA de razão 1, o que nos leva a expressão n(n+1)/2 = n^2/2 + n/2. A complexidade é dada por O(n^2/2) + O(n/2) = (1/2)O(n2) + (1/2)O(n) = O(n^2) + O(n) = O(n^2).
    c. O(100) = 1, uma vez que o segundo loop será executado 10^2 vezes.
    */

// [L1] questão 1.9
int search(int V[], int key, int n)
{
    int inf, sup, mid;
    inf = 0;
    sup = n - 1;
    while (inf <= sup)
    {
        mid = (inf + sup) / 2;
        if (key = V[mid])
            return mid;
        else if (key < V[mid])
            sup = mid - 1;
        else
            inf = mid + 1;
    }
    return -1; // not found
}

// O algoritmo é ótimo quando o elemento está no centro do vetor. O algoritmo tem o pior desempenho quando o elemento está em uma das extremidades do vetor ou não está presente no vetor.