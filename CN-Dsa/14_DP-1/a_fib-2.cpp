#include <bits/stdc++.h>
using namespace std;

int fib_dp(int num)
{
    int *arr = new int[num + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < num; i++)
    {
        arr[i] = arr[i + 1] + arr[i + 2];
    }
    return arr[num];
}

int fibHelp(int num, int *arr)
{
    if (num <= 1)
        return num;

    if (arr[num] != -1)
        return arr[num];

    int a = fibHelp(num - 1, arr);
    int b = fibHelp(num - 2, arr);

    arr[num] = a + b; // memoization
    return arr[num];
}

int fib(int num)
{
    int *arr = new int[num + 1];
    for (int i = 0; i < num + 1; i++)
    {
        arr[i] = -1;
    }
    return fibHelp(num, arr);
}

int main()
{
    int num;
    cin >> num;
    cout << fib(num);
    return 0;
}