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

/*
class Solution {
public:

int minTotalDistance(vector<vector<int>> &grid)
{
    // Write your code

    // row wise x collection
    vector<int> xp;
    vector<int> yp;

    for (int i = 0; i < grid.size(); i++)
    {

        for (int j = 0; j < grid[0].size; j++)
        {
            if (grid[i][j] == 1)
                xp.push_back(i);
        }
    }
    // col wise y collection
    for (int i = 0; i < grid[0].size(); i++)
    {

        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] == 1)
                yp.push_back(i);
        }
    }

    int x, int y;
    x = xp[xp.size() / 2];
    y = yp[yp.size() / 2];

    // dist calc.
    int dist = 0;

    for (int i : xp)
        dist += abs(x - i);

    for (int i : yp)
        dist += abs(y - i);

    return dist;
}
}
;

*/