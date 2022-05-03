#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int rminarr[n];
        int count = 0;

        int rmin[n - 1] = INT_MAX;
        for (int i = n - 2; i >= 0; i--)
        {
            rmin[i] = min(rmin[i + 1], arr[i]);
        }
        int lmax = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            lmax = max(lmax, arr[i]);
            if (rmin[i] >= lmax)
                count++;
        }
        return count;
    }
};