#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int *d;
    int front;
    int rear;
};

void Enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("queue is full");
    }
    else
        q->rear++;
    q->d[q->rear] = x;
}

int Dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
        printf("queue is empty");

    else
    {
        q->front++;
        x = q->d[q->front];
    }
    return x;
}
void createARRAY(struct Queue *t, int size)
{
    t->size = size;
    t->rear = t->front = -1;
    t->d = (int *)malloc(sizeof(int) * t->size);
}

void display(struct Queue q)
{
    int i;

    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.d[i]);
    printf("\n");
}

int main()
{
    struct Queue q;
    createARRAY(&q, 5);

    Enqueue(&q, 10);
    Enqueue(&q, 15);
    Enqueue(&q, 30);

    Dequeue(&q);
    display(q);

    return 0;
}
