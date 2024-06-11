// [L3.1] questão 3.8:
// Lista encadeada circular
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct IntNode
{
    int number;
    struct IntNode *next;
};

void insert(struct IntNode *hList, int value)
{
    struct IntNode *p, *np;
    np = (struct IntNode *)malloc(sizeof(struct IntNode));
    (*np).number = value;
    p = hList;
    while ((*p).next != hList)
        p = (*p).next;
    (*np).next = hList;
    (*p).next = np;
}

void delete(struct IntNode *hList, int value)
{
    struct IntNode *prev, *p;
    prev = hList;
    p = (*hList).next;
    while (p != hList)
    {
        if ((*p).number == value)
        {
            (*prev).next = (*p).next;
            free(p);
            p = (*prev).next;
        }
        prev = p;
        p = (*p).next;
    }
}

void print(struct IntNode *hList)
{
    struct IntNode *p;
    for (p = (*hList).next; p != hList; p = (*p).next)
        printf("%d", (*p).number);
    printf("\n");
}

int isListEmpty(struct IntNode *hList)
{
    return (*hList).next == hList;
}

int main()
{
    char option;
    int x;
    struct IntNode *head;
    head = (struct IntNode *)malloc(sizeof(struct IntNode));
    (*head).next = head;
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
            if (isListEmpty(head))
                printf("List is empty.\n");
            else
                print(head);
            break;

        case '3':
            if (isListEmpty(head))
                printf("List is empty.\n");
            else
            {
                printf("ENTER NUMBER TO DELETE: ");
                scanf("%d", &x);
                delete (head, x);
            }
            break;

        case '4':
            break;

        default:
            printf("INVALID OPTION: (%c)\n", option);
            break;
        }
        system("PAUSE");
    } while (option != '4');
    free(head);
}