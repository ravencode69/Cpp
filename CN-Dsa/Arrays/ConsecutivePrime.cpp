#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// int main() // consecutive elements are always co prime
// {
//     ll low, high;
//     cin >> low >> high;

//     cout << "YES" << endl;
//     for (int i = 0; i <= high - low; i += 2)
//     {
//         cout << low + i << " " << low + i + 1 << endl;
//     }
//     return 0;
// }

int main()
{
    vector<int> nums = {1,
                        2,
                        3,
                        4};

    vector<int> pref;
    pref.push_back(1);
    for (int x : nums)
    {
        pref.push_back(x * pref.back());
    }
    for (int x : pref)
    {
        cout << x << endl;
    }
}
class Solution
{
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &grid)
    {
        // Write your code here
        vector<int> xp;
        vector<int> yp;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    xp.push_back(i);
            }
        }
        for (int j = 0; j < grid[0].size(); j++)
        {
            for (int i = 0; i < grid.size(); i++)
            {
                if (grid[i][j] == 1)
                    yp.push_back(j);
            }
        }

        int x = xp[xp.size() / 2];
        int y = yp[yp.size() / 2];

        // distance cal

        int dist = 0;
        for (int g : xp)
        {
            dist = dist + abs(g - x);
        }

        for (int g : yp)
        {
            dist = dist + abs(g - y);
        }

        return dist;
    }
};