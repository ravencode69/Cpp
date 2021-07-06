#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;
int count(struct Node *p)
{
    int l = 0;

    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

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
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1;

    if (index < 1 || (!p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            free(p);
            return x;
        }
    }
}
int SortedCheck(struct Node *p)
{
    int x = -32765;
    while (p)
    {
        if (x > p->data)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}
void Reverse1(struct Node *p)
{

    int i = 0, *A;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int) * count(p));

    while (q)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    i--;
    q = p;
    while (q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
void SlidingpointerReverse(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void RecursiveRev(struct Node *q, struct Node *p)
{

    if (p != NULL)
    {
        RecursiveRev(p, p->next);
        p->next = q;
    }
    else
        first = q;
}
int main()
{
    int A[] = {1, 5, 7, 10, 15};
    create(A, 5);
    // //  Delete(first, 1);
    // if (SortedCheck(first) == 1)
    //     printf("Sorted");
    // else
    //     printf("Not sorted");
    RecursiveRev(NULL, first);

    RDisplay(first);

    return 0;
}