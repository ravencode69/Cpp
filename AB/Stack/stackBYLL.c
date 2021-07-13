#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
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
int pop()
{
    struct Node *p;
    int x = -1;
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
int peek(int pos)
{
    int x = -1;
    struct Node *p = top;
    for (int i = 0; i < pos - 1 && p; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        x = p->data;
    }
    return x;
}
void display()
{
    struct Node *p;
    p = top;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    printf("%d", peek(3));

    //display();
    // printf("\n %d popped off sis lol", pop());
}