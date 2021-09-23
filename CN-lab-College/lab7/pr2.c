#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

void create(int a[], int n)
{
    int i; //for scanning through array
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void RDisplay(struct Node *p)
{

    if (p)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}
void InsertSorted(struct Node *p, int x)
{

    struct Node *q, *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = p = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    InsertSorted(first, 5);
    RDisplay(first);
    return 0;
}
