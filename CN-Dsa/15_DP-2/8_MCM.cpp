/*Matrix Chain Multiplication
Send Feedback
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way
to multiply these matrices. In other words,
determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1.
Dimension of matrix Ai is p[i - 1]*p[i].
You need to find minimum number of multiplications needed to multiply the chain.*/
#include <bits/stdc++.h>

using namespace std;
int matrixChainMultiplication(int *arr, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    int m = INT_MAX;
    for (int k = start; k <= end - 1; k++)
    {
        int ans1 = matrixChainMultiplication(arr, start, k);
        int ans2 = matrixChainMultiplication(arr, k + 1, end);
        int ans3 = arr[start - 1] * arr[k] * arr[end];
        int ans = ans1 + ans2 + ans3;
        m = min(m, ans);
    }
    return m;
}

int matrixChainMultiplication(int *arr, int n)
{
    return matrixChainMultiplication(arr, 1, n);
}

// Memoization

int matrixChainMultiplication(int *arr, int start, int end, int **m)
{
    if (start >= end)
        return 0;
    if (m[start][end] != -1)
        return m[start][end];
    int temp = INT_MAX;

    for (int k = start; k <= end - 1; k++)
    {
        int a1 = matrixChainMultiplication(arr, start, k, m);
        int a2 = matrixChainMultiplication(arr, k + 1, end, m);
        int f = arr[start - 1] * arr[k] * arr[end];
        int g = a1 + a2 + f;
        temp = min(temp, g);
    }
    m[start][end] = temp;
    return m[start][end];
}

int matrixChainMultiplication(int *arr, int n)
{
    int **m = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        m[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            m[i][j] = -1;
        }
    }
    return matrixChainMultiplication(arr, 1, n, m);
}