/*Code : Knapsack

A thief robbing a store can carry a maximal weight of W into his knapsack.
There are N items, and i-th item weigh 'Wi' and the value being 'Vi.'
What would be the maximum value V, that the thief can steal?
Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
Output Format :
Print the maximum value of V that the thief can steal.
Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/
#include <bits/stdc++.h>
using namespace std;
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // Base case
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }

    if (weights[0] > maxWeight)
    {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }

    // recursive calls
    int x = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
    int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);

    int ans = max(x, y);
    return ans;
}

/*[ M E M O I Z A T I O N]*/

int knapsackRec(int *weights, int *values, int n, int maxWeight, int **arr)
{
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }
    if (arr[n][maxWeight] != -1)
    {
        return arr[n][maxWeight];
    }
    if (weights[0] > maxWeight)
    {
        arr[n][maxWeight] = knapsackRec(weights + 1, values + 1, n - 1, maxWeight, arr);
    }
    else
    {
        int res1 = values[0] + knapsackRec(weights + 1, values + 1, n - 1, maxWeight - weights[0], arr);
        int res2 = knapsackRec(weights + 1, values + 1, n - 1, maxWeight, arr);
        int res = max(res1, res2);
        arr[n][maxWeight] = res;
    }
    return arr[n][maxWeight];
}
int knapsack(int *weight, int *value, int n, int maxWeight)
{
    int **arr = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
        {
            arr[i][j] = -1;
        }
    }
    return knapsackRec(weight, value, n, maxWeight, arr);
}

/*[  D   Y    N    A   M   I   C    P R O G R A M M I N G]*/
