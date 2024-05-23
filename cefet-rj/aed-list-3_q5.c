// [L3] questão 3.5:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct IntNode
{
    int number;
    struct IntNode *next;
};

void insert(struct IntNode *hQueue, int value)
{
    struct IntNode *p, *np;
    np = (struct IntNode *)malloc(sizeof(struct IntNode));
    (*np).number = value;
    (*np).next = NULL;
    p = hQueue;
    while ((*p).next != NULL)
        p = (*p).next;
    (*p).next = np;
}

void delete(struct IntNode *hQueue)
{
    struct IntNode *p;
    p = (*hQueue).next;
    hQueue = (*p).next;
    free(p);
}

void print(struct IntNode *hQueue)
{
    struct IntNode *p;
    for (p = (*hQueue).next; p != NULL; p = (*p).next)
        printf("%d", (*p).number);
    printf("\n");
}

int isQueueEmpty(struct IntNode *hQueue)
{
    return (*hQueue).next == NULL;
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
            if (isQueueEmpty(head))
                printf("Queue is empty.\n");
            else
                print(head);
            break;

        case '3':
            if (isQueueEmpty(head))
                printf("Queue is empty.\n");
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