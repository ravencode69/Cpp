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