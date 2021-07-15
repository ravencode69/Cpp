#include <stdio.h>
int nz_elements(int arr[50][50], int n)
{
    int c = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] > 0)
                c++;
        }
    }
    return c;
}
int major_sum(int arr[50][50], int n)
{
    int c = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            c += arr[i][j];
        }
    }
    return c;
}
void minor_diagnol(int arr[50][50], int n)
{
    int c = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            printf("\t");
        }
        for (j = n - 1 - i; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
int product_diagnol(int arr[50][50], int n)
{
    int c = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        c *= arr[i][i] * arr[i][n - 1 - i];
    }
    return c;
}
int main()
{
    int arr[50][50];
    int i, j, n;
    printf("Enter n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("enter [%d][%d] element", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Number of non zero elements=%d\n", nz_elements(arr, n));
    printf("Sum of elements above major diagnol=%d\n", major_sum(arr, n));
    printf("Elements below minor diagnol\n");
    minor_diagnol(arr, n);
    printf("Product of diagnol elements=%d\n", product_diagnol(arr, n));
}