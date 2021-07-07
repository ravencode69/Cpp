
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Stack
{
    int size;
    struct Node **s;
    int top;
};

void create(struct Stack *st, int size1)
{
    st->size = size1;
    st->top = -1;
    st->s = (struct Node **)malloc(st->size * sizeof(Node *));
}
void push(struct Stack *sta, struct Node *x)
{
    if (sta->top == sta->size - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        sta->top++;
        sta->s[sta->top] = x;
    }
}
struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
        printf("stack underflow");
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}