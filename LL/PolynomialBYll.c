#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create()
{
    struct Node *t, *last = NULL;
    int num;

    printf("Enter the no. of terms \t");
    scanf("%d", &num);
    printf("Enter coff and exponent");
    for (int i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coff, &t->exp);
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p)
{

    while (p)
    {
        printf("%d x%d + ", p->coff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x)
{
    long val = 0;
    while (p)
    {
        val += p->coff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}
int main()
{
    create();
    Display(poly);
    printf("%d\n", Eval(poly, 1));

    return 0;
}