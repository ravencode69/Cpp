
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    Node **arr; // Node ** isliye banaya kyuki "node type ke pointer" ko sotre karna h na ek array mein isliye
    int size;
    int front;
    int rear;
};
void create(struct Queue *q, int s)
{
    q->front = q->rear = 0;
    q->size = s;
    q->arr = (Node **)malloc(sizeof(Node *) * q->size);
}
void Enqueue(struct Queue *q, Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Q is full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = x;
    }
}
Node *deQ(struct Queue *q)
{
    Node *x = NULL;
    if (q->front == q->rear)
        printf("q is empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}
int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}
