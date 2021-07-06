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

void Insert(struct Node *p, int pos, int x)
{
    struct Node *t;

    if (pos == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        p = first;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t->next = p->next;
            p->next = t;
        }
        else
            printf("Wrong pos entered\n");
    }
}

int main()
{
    int A[] = {9, 5, 7, 10, 15};
    create(A, 5);
    Insert(first, 0, 69);
    RDisplay(first);

    return 0;
}