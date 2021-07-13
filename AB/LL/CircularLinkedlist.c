#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;

void create(int A[], int n)
{
    struct node *t, *last;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {

        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{

    do
    {
        printf("%d  ", p->data);
        p = p->next;
    } while (p != head);
}

void Rdisplay(struct node *p)
{
    static int flag = 0;

    if (p != head || flag == 0)
    {
        flag = 1;
        printf("%d  ", p->data);
        Rdisplay(p->next);
    }

    flag = 0;
}
void Insert(struct node *p, int index, int x)

{
    struct node *t;
    int i;

    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head == 0)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;

            t->next = head;
            p->next = t;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int Delete(struct node *p, int index)
{

    int x;
    if (index < 1)
        return -1;

    if (index == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        struct node *q;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int a[] = {1, 2, 5, 7, 8};
    create(a, 5);
    // Insert(head, 5, 3);
    Delete(head, 1);
    Rdisplay(head);

    return 0;
}