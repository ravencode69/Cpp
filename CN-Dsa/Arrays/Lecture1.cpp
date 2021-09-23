/*you are given an array find the subarray with maximum sum in the array*/

//KADANE'S ALGORITHM

//if prefix sum becomes less than eq to ZERO then we discard everything before & start with a new array

#include <iostream>
using namespace std;

int maxSumSub(int *arr, int n)
{
    int globalmax = INT_MIN;
    int prefixsum = 0;
    int maxElement = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        prefixsum = max(prefixsum + arr[i + 1], 0);
        globalmax = max(prefixsum, globalmax);
        maxElement = max(maxElement, arr[i]);
    }
}

int main()
{

    return 0;
}
