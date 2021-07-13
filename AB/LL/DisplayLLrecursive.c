#include <stdio.h>
#include <stdlib.h>

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
int main()
{
    int A[] = {9, 5, 7, 10, 15};
    create(A, 5);

    RDisplay(first);

    return 0;
}