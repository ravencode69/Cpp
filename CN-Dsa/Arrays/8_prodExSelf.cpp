#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> pref(n);
        pref.push_back(1);
        for (int x : nums)
        {
            pref.push_back(x * pref.back());
        }

        vector<int> suf(n + 1);
        suf[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            suf[i] = suf[i + 1] * suf[i];
        }
        vector<int> out(n);
        for (int i = 0; i < n; i++)
        {
            out[i] = pref[i] * suf[i + 1];
        }
        return out;
    }
};