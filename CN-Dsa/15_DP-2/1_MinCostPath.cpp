#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **arr, int m, int n, int i, int j, int **op)
{
    if (i == m && j == n)
        return arr[i][j];

    if (op[i][j] != -1)
    {
        return op[i][j];
    }

    int res = INT_MAX;
    if (i + 1 <= m)
    {
        res = min(res, minCostPath(arr, m, n, i + 1, j, op));
    }
    if (i + 1 <= m && j + 1 <= n)
    {

        res = min(res, minCostPath(arr, m, n, i + 1, j + 1, op));
    }
    if (j + 1 <= n)
    {
        res = min(res, minCostPath(arr, m, n, i, j + 1, op));
    }

    int cost = res + arr[i][j];
    op[i][j] = cost;

    return cost;
}

int minCostPath(int **input, int m, int n)
{
    // Write your code here
    int **out = new int *[m];
    for (int i = 0; i < m; i++)
    {
        out[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            out[i][j] = -1;
        }
    }
    return minCostPath(input, m - 1, n - 1, 0, 0, out);
}

int minCostPath(int **input, int m, int n)
{
    int **out = new int *[m];
    for (int i = 0; i < m; i++)
    {
        out[i] = new int[n];
    }
    out[m - 1][n - 1] = input[m - 1][n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        out[m - 1][j] = input[m - 1][j] + out[m - 1][j + 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        out[i][n - 1] = input[i][n - 1] + out[i + 1][n - 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            out[i][j] = min(out[i + 1][j], min(out[i][j + 1], out[i + 1][j + 1])) + input[i][j];
        }
    }
    return out[0][0];
}
int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
    return 0;
}