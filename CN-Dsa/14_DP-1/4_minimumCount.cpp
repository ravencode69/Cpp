#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    // Write your code here
    if (n <= 0)
        return 0;

    int res = INT_MAX;
    for (int i = 1; i * i < n; i++)
    {
        int ans = minCount(n - i * i);
        res = min(ans, res);
    }
    return res + 1;
}

int minCount(int n, int *arr)
{

    if (arr[n] != -1)
    {
        return arr[n];
    }
    int res = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        int ans = minCount(n - i * i, arr);
        res = min(ans, res);
    }
    arr[n] = res + 1;
    return arr[n];
}

int minCount3(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int res = INT_MAX;
        for (int j = 2; j * j <= i; i++)
        {
            res = min(res, arr[i - j * j]);
        }
        arr[i] = res + 1;
    }
    return arr[n];
}

int minCount(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        arr[i] = -1;
    }
    return minCount(n, arr);
}
int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}