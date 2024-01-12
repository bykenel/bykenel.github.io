// QUESTÃO 1
/*
#include <stdio.h>

void printText(char *text) {
    printf("%s\n", text);
}

int main() {
    char text[] = "Hello World!";

    printText(text);
    return(0);
} 
*/


// QUESTÃO 2
/*
#include <stdio.h>

void registerAndPrintEmployee(char *name, int *birthDay, int *birthMonth, int *birthYear, float *salary, char *isManager) {
    printf("Digite o nome do funcionário: "); scanf("%s", name);
    printf("Digite o dia de nascimento: "); scanf("%d", birthDay);
    printf("Digite o mês de nascimento: "); scanf("%d", birthMonth);
    printf("Digite o ano de nascimento: "); scanf("%d", birthYear);
    printf("Digite o salário: R$"); scanf("%f", salary);
    printf("O funcionário é chefe? (S/N): "); scanf(" %c", isManager);

    printf("\n[INFORMAÇÕES DO FUNCIONÁRIO]\n");
    printf("* Nome: %s\n", name);
    printf("* Data de Nascimento: %d/%d/%d\n", *birthDay, *birthMonth, *birthYear);
    printf("* Salário: R$%.2f\n", *salary);
    printf("* É chefe? %c\n", *isManager);
}

int main() {
    char name[50], isManager;
    int birthDay, birthMonth, birthYear;
    float salary;

    registerAndPrintEmployee(name, &birthDay, &birthMonth, &birthYear, &salary, &isManager);
    return 0;
}
*/


// QUESTÃO 3
#include <stdio.h>

void registerAndPrintName(char *name, char *surname) {
    printf("Digite um nome: "); scanf("%s", name);
    printf("Digite um sobrenome: "); scanf("%s", surname);
    printf("\n%s, %s\n", surname, name);
}

int main() {
    char name[50], surname[50];

    registerAndPrintName(name, surname);
    return 0;
}