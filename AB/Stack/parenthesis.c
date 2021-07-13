#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack overflow");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct Node *p;
    char x = -1;
    if (top == NULL)
        printf("empty stack");
    else
    {
        p = top;
        x = top->data;
        top = top->next;
        free(p);
    }
    return x;
}

int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {

            if (top == NULL)

                return 0;

            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char *exp1 = "((a+b)+(c-d))";
    printf("%d", isBalanced(exp1));

    return 0;
}