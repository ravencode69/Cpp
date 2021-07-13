#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int a[], int n)
{

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
void create2(int a[], int n)
{

    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = a[0];
    second->next = NULL;
    last = second;
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
void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q = NULL;
}
void MergeLL(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p != NULL && q != NULL)
    {

        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
        if (p)
            last->next = p;
        if (q)
            last->next = q;
    }
}
int isLoop(struct Node *p)
{
    struct Node *q;
    q = p;

    do
    {
        p = p->next;
        q = q->next;
        q != NULL ? q = q->next : q;
    } while (p && q && p != q);
    return p == q ? 1 : 0;
}

int main()
{
    int A[] = {1, 2, 5, 55, 66};
    create(A, 5);

    struct Node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;

    t2->next = t1;

    printf("%d", isLoop(first));

    // int B[] = {10, 50, 70, 90, 99};
    // create2(B, 5);

    //Concat(first, second);

    MergeLL(first, second);
    RDisplay(third);

    return 0;
}
