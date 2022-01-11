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
    int mini = INT_MAX;
    for (int k = start; k <= end; k++)
    {
        int ans1 = matrixChainMultiplication(arr, start, k);
        int ans2 = matrixChainMultiplication(arr, k + 1, end);
        int ans3 = arr[start - 1] * arr[k] * arr[end];
        int ans = ans1 + ans2 + ans3;
        mini = min(mini, ans);
    }
    return mini;
}

int matrixChainMultiplication(int *arr, int n)
{
    return matrixChainMultiplication(arr, 1, n);
}
