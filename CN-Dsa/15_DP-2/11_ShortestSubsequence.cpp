#include <bits/stdc++.h>
using namespace std;

int help(string s, string v, int m, int n) // 2^n
{
    if (m == 0)
    {
        return 1001;
    }
    if (n <= 0)
    {
        return 1;
    }

    int k;
    for (k = 0; k < n; k++)
    {
        if (v[k] == s[0])
            break;
    }

    if (k == n)
        return 1;

    return min(help(s.substr(1), v, m - 1, n), 1 + help(s.substr(1), v.substr(k + 1), m - 1, n - k - 1));
}

int solve(string s, string v)
{
    int m = s.length();
    int n = v.length();
    return help(s, v, m, n);
}
// Memo
int helper(string s, string v, int m, int n, int **arr)
{
    if (m == 0)
    {
        return 1001;
    }
    if (n <= 0)
    {
        return 1;
    }
    if (arr[m][n] >= 0)
        return arr[m][n];

    int k;
    for (k = 0; k < n; k++)
    {
        if (v[k] == s[0])
            break;
    }

    if (k == n)
    {

        return 1;
    }
    arr[m][n] = min(helper(s.substr(1), v, m - 1, n, arr), 1 + helper(s.substr(1), v.substr(k + 1), m - 1, n - k - 1, arr));
    return arr[m][n];
}
int solve(string s, string v)
{

    int m = s.length();
    int n = v.length();

    int **arr = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
            arr[i][j] = -1;
    }
    return helper(s, v, m, n, arr);
}