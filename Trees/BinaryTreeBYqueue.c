#include <stdio.h>
#include "Queue.h"

struct Node *root = NULL;

void c1reate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("root value ");
    scand("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    Enqueue(&q, root->data);

    while (!isEmpty(&q))
    {
        p = deQ(&q);
        printf("enter left child");
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));

            t->data = x;

            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Enqueue(&q, t);
        }
        printf("enter right child");
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));

            t->data = x;

            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Enqueue(&q, t);
        }
    }
}
void preorderDisplay(struct Node *p)
{
    if (p)
    {
        printf("%d", p->data);
        preorderDisplay(p->lchild);
        preorderDisplay(p->rchild);
    }
}
int main()
{
    c1reate();
    preorderDisplay(root);

    return 0;
}
