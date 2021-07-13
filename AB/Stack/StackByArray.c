#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int *s;
    int top;
};

void create(struct Stack *st)
{
    printf("enter size ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}
void Display(struct Stack st)
{

    int i;
    for (i = st.top; i >= 0; i--)
    {

        printf("%d ", st.s[i]);
        printf("\n");
    }
}
void push(struct Stack *sta, int x)
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
int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("stack underflow");
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0)
    {
        printf("invalid index ");
    }
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

int main()
{
    struct Stack st;
    create(&st);

    push(&st, 22);
    push(&st, 33);
    push(&st, 44);
    push(&st, 77);
    printf("peek %d\n", peek(st, 4));

    Display(st);

    return 0;
}