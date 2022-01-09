/*Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house.
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.
The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <list>

using namespace std;
int maxMoneyLooted(int *arr, int n)
{

    // BASE CASE
    if (n <= 0)
    {
        return 0;
    }

    // RECURSIVE CALLS
    int a = arr[0] + maxMoneyLooted(arr + 2, n - 2);
    int b = maxMoneyLooted(arr + 1, n - 1);
    return max(a, b);
}

int maxMoneyLooted(int *arr, int n)
{
}