#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coff;
    int exp;
};
struct Polynomial
{
    int nz;
    struct Term *t; //taking apointer because we dont know how many terms are there
};

void create(struct Polynomial *p)
{
    int i;

    printf("Enter the number of non zero elements: ");
    scanf("%d", &p->nz);
    p->t = (struct Term *)malloc(p->nz * sizeof(struct Term));
    printf("Enter the non zero elemets\n");
    for (i = 0; i < p->nz; i++)
    {
        printf("term no. %d: ", i + 1);
        scanf("%d%d", &p->t[i].coff, &p->t[i].exp);
        printf("\n");
    }
}
void display(struct Polynomial p)
{
    int i;
    for (i = 0; i < p.nz; i++)
    {
        printf(" %d x^%d + ", p.t[i].coff, p.t[i].exp);
    }
    printf("\n");
}
struct Polynomial *add(struct Polynomial *p1, struct Polynomial *p2)
{
    int i, j, k;
    i = j = k = 0;
    struct Polynomial *sum;
    sum = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    sum->t = (struct Term *)malloc((p1->nz + p2->nz) * (sizeof(struct Term)));

    while (i < p1->nz && j < p2->nz)
    {
        if (p1->t[i].exp > p2->t[j].exp)
            sum->t[k++] = p1->t[i++];
        else if (p1->t[i].exp < p2->t[j].exp)
            sum->t[k++] = p2->t[j++];
        else
        {
            sum->t[k] = p2->t[j];
            sum->t[k++].coff = p2->t[j++].coff + p1->t[i++].coff;
        }
    }
    for (; i < p1->nz; i++)
        sum->t[k++] = p1->t[i];
    for (; j < p1->nz; j++)
        sum->t[k++] = p2->t[j];
    sum->nz = k;
    return sum;
}
int main()
{
    struct Polynomial p1, p2, *p3;

    create(&p1);
    create(&p2);
    p3 = add(&p1, &p2);
    printf("The entered polynomials are\n");
    display(p1);
    display(p2);

    printf("addition result");
    display(*p3);

    return 0;
}