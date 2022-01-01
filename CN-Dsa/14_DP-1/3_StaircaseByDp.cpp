#include <iostream>
using namespace std;
/*
long staircase(int n, long *arr)
{

    if (arr[n] != -1)
    {
        return arr[n];
    }

    long ans = staircase(n - 1, arr) + staircase(n - 2, arr) + staircase(n - 3, arr);
    arr[n] = ans;
    return arr[n];
}

long staircase(int n)
{
    // Write your code here
    long *arr = new long[n + 1];

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = -1;
    }
    return staircase(n, arr);
}
*/
//-------------------[         DP         ]-----------------------/
long staircase(int n)
{

    long *arr = new long[n + 1];

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}