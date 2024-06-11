// [L3] questão 3.4:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct IntNode
{
    int number;
    struct IntNode *next;
};

void insert(struct IntNode *hStack, int value)
{
    struct IntNode *p, *np;
    np = (struct IntNode *)malloc(sizeof(struct IntNode));
    (*np).number = value;
    p = (*hStack).next;
    (*hStack).next = np;
    (*np).next = p;
}

void delete(struct IntNode *hStack)
{
    struct IntNode *prev, *p;
    p = (*hStack).next;
    hStack = (*p).next;
    free(p);
}

void print(struct IntNode *hStack)
{
    struct IntNode *p;
    for (p = (*hStack).next; p != NULL; p = (*p).next)
        printf("%d", (*p).number);
    printf("\n");
}

int isStackEmpty(struct IntNode *hStack)
{
    return (*hStack).next == NULL;
}

int main()
{
    char option;
    int x;
    struct IntNode *head;
    head = (struct IntNode *)malloc(sizeof(struct IntNode));
    (*head).next = NULL;
    do
    {
        system("CLS");
        printf("MENU\n\n");
        printf("(1) - ADD\n");
        printf("(2) - PRINT\n");
        printf("(3) - DELETE\n");
        printf("(4) - EXIT\n\n");
        printf("SELECT AN OPTION: ");
        scanf("\n%c", &option);

        switch (option)
        {
        case '1':
            printf("ENTER NUMBER TO ADD: ");
            scanf("%d", &x);
            insert(head, x);
            break;

        case '2':
            if (isStackEmpty(head))
                printf("Stack is empty.\n");
            else
                print(head);
            break;

        case '3':
            if (isStackEmpty(head))
                printf("Stack is empty.\n");
            else
            {
                delete(head);
            }
            break;

        case '4':
            break;

        default:
            printf("INVALID OPTION: (%c)\n", option);
            break;
        }
        system("PAUSE");
    } while (option != '5');
    free(head);
}