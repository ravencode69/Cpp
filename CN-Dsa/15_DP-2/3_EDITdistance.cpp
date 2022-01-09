/*Code : Edit Distance

Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other.
In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character*/

/*SIMPLE RECURSIVE CODE*/
#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2)
{
    // Base case
    if (s2.length() == 0)
        return s1.length();
    if (s1.length() == 0)
        return s2.length();

    // recursive calls
    if (s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));

    else
    {
        int x = 1 + editDistance(s1, s2.substr(1));           // deleting the first character
        int y = 1 + editDistance(s1.substr(1), s2);           // Inserting the first character
        int z = 1 + editDistance(s1.substr(1), s2.substr(1)); // Replacing the first character

        int ans = min(x, min(y, z));
        return ans;
    }
}
/*MEMOIZATION*/

int editDistance2(string s1, string s2, int **out)
{
    int m = s1.length();
    int n = s2.length();
    if (m == 0 || n == 0)
    {
        return max(m, n);
    }
    // check if exist
    if (out[m][n] != -1)
    {
        return out[m][n];
    }

    if (s1[0] == s2[0])
    {
        out[m][n] = editDistance2(s1.substr(1), s2.substr(1), out);
    }
    else
    {
        int x = 1 + editDistance2(s1, s2.substr(1), out);
        int y = 1 + editDistance2(s1.substr(1), s2, out);
        int z = 1 + editDistance2(s1.substr(1), s2.substr(1), out);

        out[m][n] = min(x, min(y, z));
    }

    return out[m][n];
}

int editDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    int **out = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        out[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            out[i][j] = -1;
        }
    }
    return editDistance2(s1, s2, out);
}

/*DYNAMIC PROGRAMMING SOLUTION*/

int editDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **out = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        out[i] = new int[n + 1];
    }

    for (int j = 0; j < n + 1; j++)
    {
        out[0][j] = j;
    }
    for (int i = 1; i < m + 1; i++)
    {
        out[i][0] = i;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[m - i] == s2[n - j])
            {
                out[i][j] = out[i - 1][j - 1];
            }
            else
            {
                int x = 1 + out[i - 1][j];
                int y = 1 + out[i][j - 1];
                int z = 1 + out[i - 1][j - 1];
                out[i][j] = min(x, min(y, z));
            }
        }
    }
    return out[m][n];
}