#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
struct TPilha {
    int m;  //tamanho
    int t;  //topo
    int *v; //valores
};

void criarPilha(struct TPilha *p, int n) {
  (*p).m  = n;
  (*p).t = -1;
  (*p).v  = (int *)malloc(sizeof(int[n]));
}

int elementosNaPilha(struct TPilha p) {
  return p.t + 1;
}

int buscarNaPilha(struct TPilha p, int x) {
  int i, busca;
  busca = -1; //flag para erro
  for (i=0; i <= p.t; i = i + 1)
    if (p.v[i] == x) {
      busca = i;
      i = p.t + 1;
    }
  return busca;
}

int inserirNaPilha(struct TPilha *p, int x) {
  int i, M;
  M = elementosNaPilha(*p);
  if (M < (*p).m)
    if (buscarNaPilha(*p, x) == -1) {
      (*p).t = (*p).t + 1;
      (*p).v[(*p).t] = x;
      return 1;
    }
    else return 0; //Elemento já existe
  else return -1; //Overflow
}

int excluirDaPilha(struct TPilha *p) {
  int i, M;
  M = elementosNaPilha(*p);
  if (M > 0) {
    (*p).t = (*p).t - 1;
    return 1;
  }
  else return -1; //Underflow
}

void eliminarPilha(struct TPilha *p) {
  (*p).m = 0;
  (*p).t = -1;
  free((*p).v);
}
*/


//questão 2.5:
    struct TFila {
        int m;  //tamanho
        int i;  //início
        int r;  //retaguarda
        int *v; //valores
    };
    
    int mod(int x, int y) {
        int m = x % y;
        if (m < 0) m += y;
        return m;
        //return (x % y < 0 ? x % y+ y : x % y);
    }
    
    void criarFila(struct TFila *f, int n) {
        (*f).m = n;
        (*f).i = -1;
        (*f).r = -1;
        (*f).v = (int *)malloc(sizeof(int[n]));
    }

    int elementosNaFila(struct TFila f) {
        if (f.r == -1 && f.i == -1) return 0;
        else return 1 + mod(f.r - f.i, f.m);
    }

    int buscarNaFila(struct TFila f, int x) {
        int i, q, busca, M = elementosNaFila(f);
        busca = -1; //flag para erro
        for (i = f.i, q = 1; q <= M; i++, q++) {
            if (f.v[mod(i, f.m)] == x) {
                busca = i;
                q = M + 1;
            }
        }
        return busca;
    }

    int inserirNaFila(struct TFila *f, int x) {
        int aux = mod((*f).r + 1, (*f).m);
        if (aux != (*f).i) {
            (*f).r = aux;
            (*f).v[(*f).r] = x;
            if ((*f).i == -1) (*f).i = (*f).i + 1; 
            return 1;
        }
        else return -1; //Overflow
    }

    int excluirDaFila(struct TFila *f) {
        int i, valor, M;
        if ((*f).i != -1) {
            valor = (*f).v[(*f).i];
            if ((*f).i == (*f).r) {
                (*f).i = -1;
                (*f).r = -1;
            }
            else (*f).i = mod((*f).i + 1, (*f).m);
            return 1;
        }
        else return 0; //Underflow
    }

    void eliminarFila(struct TFila *f) {
        (*f).m = 0;
        (*f).i = -1;
        (*f).r = -1;
        free((*f).v);
    }


//questão 2.6:
    int tamanho(char *s) {
        int i;
        for (i = 0; s[i] != '\0'; i++);
        return i;
    }

    int operando(char c) {
        return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
    }

    int operador(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    int main() {
        char *pilha, *exp, *pol, op;
        int fim, indexp, indpol, topo, erro;

        pilha = (char *)malloc(sizeof(char));
        exp = (char *)malloc(sizeof(char));
        pol = (char *)malloc(sizeof(char));

        printf("Entre com a expressao:\n\n");
        gets(exp);

        fim = tamanho(exp);
        indexp = 0;
        topo = -1;
        indpol = -1;
        erro = 0;

        while (indexp < fim) {
            if (operando(exp[indexp])) {
                indpol = indpol + 1;
                pol[indpol] = exp[indexp];
            }
            else if (operador(exp[indexp])) {
                topo = topo + 1;
                pilha[topo] = exp[indexp];
            }
            else if (exp[indexp] == ")") {
                if (topo != -1) {
                    op = pilha[topo];
                    topo = topo - 1;
                    indpol = indpol + 1;
                    pol[indpol] = op;
                }
                else erro = 1;
            }
            indexp = indexp + 1;
        }

        if (!erro) printf("%s", pol);
        else printf("Expressao errada.", pol);

        free(pilha);
        free(exp);
        free(pol);
        getchar();
    }