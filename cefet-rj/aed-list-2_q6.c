// [L2.1] questão 2.6:
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int length(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

int operand(char c)
{
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

int operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main()
{
    char *stack, *expr, *postfix, op;
    int end, indexExpr, indexPostfix, top, error;

    stack = (char *)malloc(sizeof(char));
    expr = (char *)malloc(sizeof(char));
    postfix = (char *)malloc(sizeof(char));

    printf("Enter the expression:\n\n");
    gets(expr);

    end = length(expr);
    indexExpr = 0;
    top = -1;
    indexPostfix = -1;
    error = 0;

    while (indexExpr < end)
    {
        if (operand(expr[indexExpr]))
        {
            indexPostfix = indexPostfix + 1;
            postfix[indexPostfix] = expr[indexExpr];
        }
        else if (operator(expr[indexExpr]))
        {
            top = top + 1;
            stack[top] = expr[indexExpr];
        }
        else if (expr[indexExpr] == ")")
        {
            if (top != -1)
            {
                op = stack[top];
                top = top - 1;
                indexPostfix = indexPostfix + 1;
                postfix[indexPostfix] = op;
            }
            else
                error = 1;
        }
        indexExpr = indexExpr + 1;
    }

    if (!error)
        printf("%s", postfix);
    else
        printf("Invalid expression.", postfix);

    free(stack);
    free(expr);
    free(postfix);
    getchar();
}