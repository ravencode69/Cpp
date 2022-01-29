#include <stdio.h>
#include <string.h>
struct player
{
    char name[30];
    int age;
    long DOB; // DD/MM/YY
};

void display(struct player st)
{
    if (st.age > 21)
    {
        printf("Name %s", st.name);
        printf("\n");
        printf("Age %d", st.age);
        printf("\n");
        printf("DOB(DD/MM/YY) %d", st.DOB);
        printf("\n");
    }
}
int main()
{
    struct player st[7];

    for (int i = 0; i < 7; i++)
    {

        scanf("%[^\n]%*c", st[i].name);
        scanf("%d", &st[i].age);
        scanf("%d", &st[i].DOB);
    }
    for (int i = 0; i < 7; i++)
    {
        display(st[i]);
    }
}