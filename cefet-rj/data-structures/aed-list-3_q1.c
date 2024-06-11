// [L3] questão 3.1:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct IntNode
{
    int number;
    struct IntNode *next;
} *head;

void insert(int value)
{
    struct IntNode *p, *np;
    np = (struct IntNode *)malloc(sizeof(struct IntNode));
    (*np).number = value;
    (*np).next = NULL;
    p = head;
    while ((*p).next != NULL)
        p = (*p).next;
    (*p).next = np;
}

void delete(int value)
{
    struct IntNode *prev, *p;
    prev = head;
    p = (*head).next;
    while (p != NULL)
    {
        if ((*p).number == value)
        {
            (*prev).next = (*p).next;
            free(p);
        }
        prev = (*prev).next;
        p = (*p).next;
    }
}

void print()
{
    struct IntNode *p;
    for (p = (*head).next; p != NULL; p = (*p).next)
        printf("%d", (*p).number);
    printf("\n");
}

void sort()
{
    struct IntNode *pivot, *p;
    for (pivot = (*head).next; pivot != NULL; pivot = (*pivot).next)
    {
        for (p = (*pivot).next; p != NULL; p = (*p).next)
        {
            if ((*p).number < (*pivot).number)
            {
                int aux = (*pivot).number;
                (*pivot).number = (*p).number;
                (*p).number = aux;
            }
        }
    }
}

int isListEmpty()
{
    return (*head).next == NULL;
}

int main()
{
    char option;
    int x;
    head = (struct IntNode *)malloc(sizeof(struct IntNode));
    (*head).next = NULL;
    do
    {
        system("CLS");
        printf("MENU\n\n");
        printf("(1) - ADD\n");
        printf("(2) - PRINT\n");
        printf("(3) - DELETE\n");
        printf("(4) - SORT\n");
        printf("(5) - EXIT\n\n");
        printf("SELECT AN OPTION: ");
        scanf("\n%c", &option);

        switch (option)
        {
        case '1':
            printf("ENTER NUMBER TO ADD: ");
            scanf("%d", &x);
            insert(x);
            break;

        case '2':
            if (isListEmpty())
                printf("List is empty.\n");
            else
                print();
            break;

        case '3':
            if (isListEmpty())
                printf("List is empty.\n");
            else
            {
                printf("ENTER NUMBER TO DELETE: ");
                scanf("%d", &x);
                delete (x);
            }
            break;

        case '4':
            sort();
            break;

        case '5':
            break;

        default:
            printf("INVALID OPTION: (%c)\n", option);
            break;
        }
        system("PAUSE");
    } while (option != '5');
    free(head);
}