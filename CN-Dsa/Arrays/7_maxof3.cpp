#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1 = -(int)1e9;

        int max2 = max1;
        int max3 = max1;

        int min1 = (int)1e9;
        int min2 = (int)1e9;

        for (int i = 0; i <= nums.size(); i++)
        {

            if (nums[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max3)
            {
                max3 = nums[i];
            }
            // min check
            if (nums[i] < min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2)
            {
                min2 = nums[i];
            }
        }

        return max(max1 * min1 * min2, max1 * max2 * max3);
    }
};
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int mini = (int)1e9;
        int smin = (int)1e9;

        int maxi = -(int)1e9;
        int smax = maxi;
        int tmax = maxi;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxi)
            {
                tmax = smax;
                smax = maxi;
                maxi = nums[i];
            }
            else if (nums[i] > smax)
            {
                tmax = smax;
                smax = nums[i];
            }
            else if (nums[i] > tmax)
            {
                tmax = nums[i];
            }

            if (nums[i] < mini)
            {
                smin = mini;
                mini = nums[i];
            }
            else if (nums[i] < smin)
            {
                smin = nums[i];
            }
        }

        return max(maxi * smax * tmax, maxi * mini * smin);
    }
};