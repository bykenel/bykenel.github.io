#include <stdio.h>
#include <stdlib.h>

/*
void criarLista(int ***l, int n) {
  int i;
  *l = (int **)malloc(sizeof(int*[n]));
  for(i=0; i < n; i = i+1)
    (*l)[i] = NULL;
}

int elementosNaLista(int ** l, int n) {
  int i;
  for(i=0; i < n; i = i+1)
    if (l[i] == NULL) break;
  return i;
}

int buscarNaLista(int ** l, int n, int x) {
  int i, busca;
  busca = -1; //flag para erro
  for (i=0; i < n; i = i+1) {
    if (l[i] == NULL) i = n;
    else if (*(l[i]) == x)
         {
           busca = i;
           i = n;
         }
  }
  return busca;
}

int inserirNaLista(int ** l, int n, int x) {
  int i, M;
  M = elementosNaLista(l,n);
  if (M<n)
    if (buscarNaLista(l, n, x) == -1) {
      l[M] = (int *)malloc(sizeof(int)); 
     *l[M] = x;
      return 1;
    }
    else return 0; //Elemento já existe
  else return -1; //Overflow
}

int excluirDaLista(int ** l, int n, int x) {
  int i, indice, M = elementosNaLista(l,n);
  if (M = = 0) return -1; //Underflow
  else { indice = buscarNaLista(l, n, x);
         if (indice = = -1) return 0; //Elemento não existe
         else {
                if (indice = = n-1) { free(l[indice]);
                                     l[indice] = NULL;
                                    }
                else {
                  free(l[indice]); 		
                  for (i = indice; i < M; i = i+1) l[i] = l[i+1];
                  l[M-1] = NULL;        
                }
                return 1;
              }
       }
}

void imprimirLista(int ** l, int n) {
  int i, M;
  for (i = 0; i < n; i = i+1)
    if (l[i] == NULL)
      printf("NULL\n");
    else printf("%d\n", *(l[i]));
  printf("\n");
}

void limparLista(int ***l, int n) {
  int i;
  for(i=0; i < n; i = i+1)
    if ((*l)[i] != NULL) free((*l)[i]);
  free(*l);
} 
*/


//questão 2.1:
    int buscarNaLista(int ** l, int n, int x) {
        int i, busca;
        l[n] = (int *)malloc(sizeof(int)); // Alocando uma nova posição
        M = elementosNaLista(l, n);
        *(l[M]) = x;
        busca = -1; // Flag para erro
        for (i = 0; *(l[i]) != x; i = i + 1);
        if (i != M) busca = i;
        free(l[n]); // Liberando a nova posição alocada
        return busca;
    }


//questão 2.2:
    int buscarNaListaOrdenada(int ** l, int n, int x) { // n é o maior índice da lista
        int i, busca;
        busca = -1; // flag para erro
        for (i = 0; (l[i] != NULL) && (*(l[i]) < x); i = i + 1);
        if (l[i] != NULL && *l[i] == x) busca = i;
        return busca;
    }


//questão 2.3:
    int buscaBinaria(int ** l, int n, int x) {
        int inf, sup, meio, busca;
        inf = 0;
        sup = n - 1;
        busca = -1; // flag para erro
        while (inf <= sup) {
            meio = (inf + sup) / 2;
            if (l[meio] == NULL || (*l[meio]) > x)
                sup = meio - 1;
            else if ((*l[meio]) < x) inf = meio + 1;
            else
                busca = meio;
        }
        return busca;
    }


//questão 2.4:
    void ordenarLista(int ** l, int n) {
        int i, j, aux, M;
        M = elementosNaLista(l, n);
        for (i = M - 1; i > 1; i = i - 1)
            for (j = 0; j < i; j = j + 1)
                if (*l[j] > *l[j + 1]) {
                    aux = *l[j];
                    *l[j] = *l[j + 1];
                    *l[j + 1] = aux;
                }
    }