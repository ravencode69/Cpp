#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{

    int n_aks_006;
    int count = 0;
    printf("\nEnter size:- ");

    scanf("%d", &n_aks_006);

    int arr[n_aks_006];
    printf("WORST CASE");
    printf("\nEnter value:- ");
    for (int i = 0; i < n_aks_006; i++)
    {
        scanf("%d", &arr[i]);
    }

    clock_t t;
    t = clock();
    for (int i = 1; i < n_aks_006; i++)
    {

        1906569

            int data = arr[i];
        int j = i;
        count++;

        while (j > 0 && data < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
            count++;
        }
        arr[j] = data;
    }

    t = clock() - t;

    double

        time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nTotal frequency count is: %d", count + 1);

    printf("\nWORST time taken for Insertion Sort is %f seconds to excute", time_taken);
    count = 0;
    printf("\nAVERAGE CASE");

    printf("\nEnter value:");
    for (int i = 0; i < n_aks_006; i++)
    {
        scanf("%d", &arr[i]);
    }
    //clock_t t;
    t = clock();

    for (int i = 1; i < n_aks_006; i++)
    {

        1906569

            int data = arr[i];
        int j = i;
        count++;

        while (j > 0 && data < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
            count++;
        }
        arr[j] = data;
    }

    t = clock() - t;

    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nTotal frequency count is: %d", count + 1);

    printf("\n AVERAGE time taken for Insertion Sort is %f seconds to excute", time_taken);

    count = 0;
    printf("\nBEST CASE");
    printf("\nEnter value:");

    for (int i = 0; i < n_aks_006; i++)
    {
        scanf("%d", &arr[i]);
    }

    //clock_t t;
    t = clock();
    for (int i = 1; i < n_aks_006; i++)
    {
        int data = arr[i];

        int j = i;
        count++;
        while (j > 0 && data < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
            count++;
        }
        arr[j] = data;
    }
    t = clock() - t;

    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nTotal frequency count is: %d", count + 1);

    printf("\n BEST time taken for Insertion Sort is %f seconds to excute\n", time_taken);

    for (int i = 0; i < n_aks_006; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
