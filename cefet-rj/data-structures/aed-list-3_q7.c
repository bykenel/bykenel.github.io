// [L3] question 3.7:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct IntNode
{
    int number;
    struct IntNode *next;
};

// a.
void newLinkedList(struct IntNode *ptr1, struct IntNode *ptr2)
{
    struct IntNode *p1;
    struct IntNode *p2, *last;
    p1 = (*ptr1).next;
    if (p1 != NULL)
    {
        last = (struct IntNode *)malloc(sizeof(struct IntNode));
        (*last).number = (*p1).number;
        (*last).next = NULL;
        (*ptr2).next = last;
        p1 = (*p1).next;
    }
    while (p1 != NULL)
    {
        for (p2 = (*ptr2).next; (*p2).next != last; p2 = (*p2).next);
        (*p2).next = (struct IntNode *)malloc(sizeof(struct IntNode));
        (*(*p2).next).number = (*p1).number;
        (*(*p2).next).next = last;
        p1 = (*p1).next;
    }
}

// b.
void newLinkedList(struct IntNode **ptr1)
{
    struct IntNode *p1;
    struct IntNode *p2, *np;
    p2 = (struct IntNode *)malloc(sizeof(struct IntNode));
    (*p2).next = NULL;
    p1 = *ptr1;
    while (p1 != NULL)
    {
        np = (struct IntNode *)malloc(sizeof(struct IntNode));
        (*np).number = (*p1).number;
        (*np).next = (*p2).next;
        (*p2).next = np;
        p1 = (*p1).next;
    }
    *ptr1 = p2;
}