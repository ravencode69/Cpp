#include <stdio.h>

#include <math.h>

//O(n square and O(1) space)
void count_freq1(int n_aks_006, int nums[100])
{

    for (int i = 0; i < n_aks_006; i++)
    {
        int count = 0;
        for (int j = 0; j < n_aks_006; j++)
        {
            if (nums[j] == nums[i])
            {

                count++;
            }
            if (count >= ceil((double)(n_aks_006 / 2)))

            {
                printf("O(n^2):YES\n");
                return;
            }
        }
    }
    printf("O(n^2):NO\n");
}

// O(n) and O(1) extra space

void count_freq2(int n, int nums[100])

{

    int count = 0;
    int candidate = -1;

    for (int i_aks_006 = 0; i_aks_006 < n; i_aks_006++)
    {
        if (count == 0)

        {
            candidate = nums[i_aks_006];
        }

        count += (nums[i_aks_006] == candidate) ? 1 : -1;
    }

    count = 0;

    for (int i_aks_006 = 0; i_aks_006 < n; i_aks_006++)
    {
        if (nums[i_aks_006] == candidate)

            count++;
    }

    if (count >= ceil((double)(n / 2)))
    {
        printf("O(n):YES\n");
    }
    else
        printf("O(n):NO\n");
}

int main()
{
    int n;

    printf("\nEnter size:-");

    scanf("%d", &n);

    int nums[n];

    printf("\nEnter value:-");

    for (int i_aks_006 = 0; i_aks_006 < n; i_aks_006++)

    {

        scanf("%d", &nums[i_aks_006]);
    }

    count_freq1(n, nums);
    count_freq2(n, nums);

    return 0;
}
