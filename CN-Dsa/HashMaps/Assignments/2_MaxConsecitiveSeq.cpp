#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{

    unordered_map<int, bool> map;

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]] = true;
    }

    int maxlength = 0;
    int start = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (!map.count(arr[i] - 1))
        {
            int currentnum = arr[i];
            int currentstreak = 1;

            while (map.count(currentnum + 1))
            {
                currentnum += 1;
                currentstreak += 1;
            }
            if (currentstreak > maxlength)
            {
                maxlength = currentstreak;
                start = arr[i];
            }
        }
    }
    for (int i = 0; i < maxlength; i++)
    {
        ans.push_back(start);
        start++;
    }
    return ans;
}