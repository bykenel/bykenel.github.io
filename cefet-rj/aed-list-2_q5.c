#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
struct TStack
{
    int s;  // size
    int t;  // top
    int *v; // values
};

void createStack(struct TStack *p, int n)
{
    (*p).s = n;
    (*p).t = -1;
    (*p).v = (int *)malloc(sizeof(int[n]));
}

int stackElements(struct TStack p)
{
    return p.t + 1;
}

int searchStack(struct TStack p, int x)
{
    int i, search;
    search = -1; // flag for error
    for (i = 0; i <= p.t; i = i + 1)
        if (p.v[i] == x)
        {
            search = i;
            i = p.t + 1;
        }
    return search;
}

int pushStack(struct TStack *p, int x)
{
    int i, M;
    M = stackElements(*p);
    if (M < (*p).s)
        if (searchStack(*p, x) == -1)
        {
            (*p).t = (*p).t + 1;
            (*p).v[(*p).t] = x;
            return 1;
        }
        else
            return 0; // Element already exists
    else
        return -1; // Overflow
}

int popStack(struct TStack *p)
{
    int i, M;
    M = stackElements(*p);
    if (M > 0)
    {
        (*p).t = (*p).t - 1;
        return 1;
    }
    else
        return -1; // Underflow
}

void deleteStack(struct TStack *p)
{
    (*p).s = 0;
    (*p).t = -1;
    free((*p).v);
}
*/

// [L2.1] questão 2.5:
struct TQueue
{
    int s;  // size
    int f;  // front
    int r;  // rear
    int *v; // values
};

int mod(int x, int y)
{
    int m = x % y;
    if (m < 0)
        m += y;
    return m;
    // return (x % y < 0 ? x % y + y : x % y);
}

void createQueue(struct TQueue *q, int n)
{
    (*q).s = n;
    (*q).f = -1;
    (*q).r = -1;
    (*q).v = (int *)malloc(sizeof(int[n]));
}

int queueElements(struct TQueue q)
{
    if (q.r == -1 && q.f == -1)
        return 0;
    else
        return 1 + mod(q.r - q.f, q.s);
}

int searchQueue(struct TQueue q, int x)
{
    int i, count, search, M = queueElements(q);
    search = -1; // flag for error
    for (i = q.f, count = 1; count <= M; i++, count++)
    {
        if (q.v[mod(i, q.s)] == x)
        {
            search = i;
            count = M + 1;
        }
    }
    return search;
}

int enqueue(struct TQueue *q, int x)
{
    int aux = mod((*q).r + 1, (*q).s);
    if (aux != (*q).f)
    {
        (*q).r = aux;
        (*q).v[(*q).r] = x;
        if ((*q).f == -1)
            (*q).f = (*q).f + 1;
        return 1;
    }
    else
        return -1; // Overflow
}

int dequeue(struct TQueue *q)
{
    int i, value, M;
    if ((*q).f != -1)
    {
        value = (*q).v[(*q).f];
        if ((*q).f == (*q).r)
        {
            (*q).f = -1;
            (*q).r = -1;
        }
        else
            (*q).f = mod((*q).f + 1, (*q).s);
        return 1;
    }
    else
        return 0; // Underflow
}

void deleteQueue(struct TQueue *q)
{
    (*q).s = 0;
    (*q).f = -1;
    (*q).r = -1;
    free((*q).v);
}