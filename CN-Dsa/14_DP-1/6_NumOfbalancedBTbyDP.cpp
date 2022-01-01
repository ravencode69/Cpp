#include <iostream>
using namespace std;
#define M 1000000007
int balancedBT(int n, int *arr)
{
    if (arr[n] != -1)
    {
        return arr[n];
    }

    int a = balancedBT(n - 1, arr);
    int b = balancedBT(n - 2, arr);

    int ans1 = (int)(((long)(a)*a) % M);
    int ans2 = (int)((2 * (long)(a)*b) % M);

    arr[n] = (int)(ans1 + ans2) % M;
    return arr[n];
}

int balancedBTs(int n)
{
    // Write your code here
    int *arr = new int[n + 1];
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = -1;
    }
    return balancedBT(n, arr);
}
int balancedBTs(int n)
{
    int *arr = new int[n + 1];
    arr[0] = arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int a = arr[i - 1];
        int b = arr[i - 2];

        int ans = (int)(((long)(a)*a) % M);
        int ans2 = (int)((2 * (long)(a)*b) % M);
        arr[i] = (int)(ans + ans2) % M;
    }
    return arr[i];
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}