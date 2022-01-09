#include <bits/stdc++.h>
using namespace std;

int lcs(string S, string T)
{
    if (S.length() == 0 || T.length() == 0)
    {
        return 0;
    }

    if (S[0] == T[0])
        return 1 + lcs(S.substr(1), T.substr(1));
    else
    {
        int x = lcs(S.substr(1), T);
        int y = lcs(S, T.substr(1));
        return max(x, y);
    }
}
int lcs_m(string S, string T, int **out)
{

    int m = S.size();
    int n = T.size();
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (out[m][n] != -1)
    {
        return out[m][n];
    }
    int ans;
    if (S[0] == T[0])
        ans = 1 + lcs_m(S.substr(1), T.substr(1), out);
    else
    {
        int x = lcs_m(S.substr(1), T, out);
        int y = lcs_m(S, T.substr(1), out);
        int z = lcs_m(S.substr(1), T.substr(1), out);
        ans = max(z, max(x, y));
    }
    // storage
    out[m][n] = ans;
    return ans;
}
int lcs2(string S, string T)
{
    int m = S.length();
    int n = T.length();

    int **out = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        out[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
            out[i][j] = -1;
    }
    return lcs_m(S, T, out);
}

/*----------------------[ DYNAMIC PROGRAMMING ]--------------------------------------*/
int lcsdp(string S, string T)
{
    int m = S.length();
    int n = T.length();

    int **out = new int[m + 1];

    // col
    for (int j = 0; j <= n; j++)
    {
        out[0][j] = 0;
    }
    // row
    for (int i = 1; i <= m; i++)
    {
        out[i][0] = 0;
    }

    for (int i = 1; i < m + 1; i++)
    {
        out[i] = new int[n + 1];
        for (int j = 1; j < n + 1; j++)
        {
            if (S[m - i] = T[n - j])
                out[i][j] = 1 + out[i - 1][j - 1];

            else
            {
                int x = out[i - 1][j];
                int y = out[i][j - 1];
                int z = out[i - 1][j - 1];

                out[i][j] = max(x, max(y, z));
            }
        }
    }
    return out[m][n];
}

int main()
{
    string S = "A";
    string Y = "Alyssa";
    cout << lcsdp(S, Y);
}
