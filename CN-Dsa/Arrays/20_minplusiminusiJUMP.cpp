#include <bits/stdc++.h>
using namespace std;

int solve(int value)
{
    int sum = 0;
    int jump = 1;

    while (sum < value)
    {
        sum = sum + jump;
        jump++;
    }

    if ((sum - value) % 2 == 0)
        return jump - 1;
    else
    {
        if ((sum + jump - value) % 2 == 0)
        {
            return jump;
        }
        else
        {
            return jump + 1;
        }
    }
}