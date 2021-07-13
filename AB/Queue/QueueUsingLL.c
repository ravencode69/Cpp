#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;

} *front = NULL, *rear = NULL;

void enQ(int x)
{
    struct Queue *temp;
    temp = (struct Queue *)malloc(sizeof(struct Queue));

    if (temp == NULL)
        printf("Heap full queue is full");
    else
    {
        temp->data = x;
        temp->next = NULL;
        if (front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

int deQ()
{
    int x = -1;
    struct Queue *q;
    if (front == NULL)
        printf("Queue is empty");
    else
    {
        q = front;
        x = q->data;
        front = front->next;
        free(q);
    }
    return x;
}
void display()
{
    struct Queue *t = front;
    while (t)
    {
        printf("%d", t->data);
        t = t->next;
    }
    printf("\n");
}
int main()
{
    enQ(10);
    enQ(20);
    enQ(30);
    deQ();
    display();

    return 0;
}
