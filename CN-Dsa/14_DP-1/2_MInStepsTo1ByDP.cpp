#include <bits/stdc++.h>
using namespace std;

int countStepsToOne(int n)
{
    int *arr = new int[n + 1];
    arr[1] = 0;

    for (int i = 2; i < n; i++)
    {
        int x = arr[i - 1];

        if (i % 2 == 0)
            x = min(x, arr[i / 2]);
        if (i % 3 == 0)
            x = min(x, arr[i / 3]);
        arr[i] = x + 1;
    }
    return arr[n];
}

int countStepsToOne(int n, int *arr) // memoization
{
    // Write your code here
    if (n == 1)
        return 0;

    if (arr[n] != -1)
        return arr[n];
    int y = INT_MAX, z = INT_MAX;
    int x = countStepsToOne(n - 1, arr);
    if (n % 2 == 0)
        y = countStepsToOne(n / 2, arr);
    if (n % 3 == 0)
        z = countStepsToOne(n / 3, arr);

    int ans = min(x, min(y, z)) + 1;
    arr[n] = ans;
    return arr[n];
}
int countStepsToOne(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    return countStepsToOne(n, arr);
}

int main()
{
    int n;
    cin >> n;
    cout << countStepsToOne(n);
}