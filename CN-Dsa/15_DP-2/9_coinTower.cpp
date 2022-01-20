#include <bits/stdc++.h>
using namespace std;
// Recursion
#include <bits/stdc++.h>
using namespace std;

int findwinnergame(int n, int x, int y)
{
    if (n <= 0)
        return 0;
    int ans1 = 1 ^ findwinnergame(n - 1, x, y);
    int ans2 = 0;
    if (n >= x)
    {
        ans2 = 1 ^ findwinnergame(n - x, x, y);
    }
    int ans3 = 0;
    if (n >= y)
    {
        ans3 = 1 ^ findwinnergame(n - y, x, y);
    }
    if (ans1 + ans2 + ans3 > 0)
        return 1;

    return 0;
}

string findWinner(int n, int x, int y)
{
    if (findwinnergame(n, x, y) > 0)
        return "Beerus";
    return "Whis";
}

// Memo
int findwinnerg(int n, int x, int y, int *dp)
{

    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans1 = 1 ^ findwinnerg(n - 1, x, y, dp);
    int ans2 = 0;
    if (n >= x)
        ans2 = 1 ^ findwinnerg(n - x, x, y, dp);
    int ans3 = 0;
    if (n >= y)
        ans3 = 1 ^ findwinnerg(n - y, x, y, dp);

    if (ans1 + ans2 + ans3 > 0)
        dp[n] = 1;
    else
    {
        dp[n] = 0;
    }
    return dp[n];
}
string findWinner(int n, int x, int y)
{
    int *m = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        m[i] = -1;
    }

    if (findwinnerg(n, x, y, m) == 1)
        return "Beerus";
    else
        return "Whis";
}
// DP

string findWinner(int n, int x, int y)
{
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i - 1 >= 0 && !dp[i - 1])
            dp[i] = 1;
        else if (i - x >= 0 && !dp[i - x])
            dp[i] = 1;
        else if (i - y >= 0 && !dp[i - y])
            dp[i] = 1;
        else
            dp[i] = 0;
    }
    if (dp[n] == 1)
        return "Beerus";
    else
        return "Whis";
}