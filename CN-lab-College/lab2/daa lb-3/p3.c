#include <stdio.h>
int square_root(int n)
{
    if (n == 0 | n == 1)
    {
        return n;
    }
    int ans = 0;

    int l_aks_006 = 1, r = n;

    while (l_aks_006 <= r)
    {
        int mid = (l_aks_006 + r) / 2;
        if (mid * mid == n)
            return mid;
        if (mid * mid <= n)
        {
            ans = mid;
            l_aks_006 = mid + 1;
        }

        else
            r = mid - 1;
    }

    return ans;
}

int main()

{
    int n;
    printf("Enter any positive integer to find its square root over: ");
    scanf("%d", &n);
    printf("the swqare root of %d is : %d\n", n, square_root(n));
    return 0;
}
