#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    unordered_map<int, int> map; //sum, index
    int sum = 0;
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxlen = max(maxlen, i + 1);
        }

        if (map.find(sum) != map.end())
        {
            maxlen = max(maxlen, i - map[sum]);
        }
        else
            map[sum] = i;
    }
    return maxlen;
}