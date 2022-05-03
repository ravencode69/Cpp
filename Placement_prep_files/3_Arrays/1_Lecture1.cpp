/* Q-1 you are given an array find the subarray with maximum sum in the array*/

// KADANE'S ALGORITHM

// if prefix sum becomes less than eq to ZERO then we discard everything before & start with a new array

#include <iostream>
#include <climits>
using namespace std;

int maxSumSub(int *arr, int n)
{
    int globalmax = INT_MIN;
    int prefixsum = 0;
    int maxElement = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        prefixsum = max(prefixsum + arr[i], 0);
        globalmax = max(prefixsum, globalmax);
        maxElement = max(maxElement, arr[i]);
    }
    if (globalmax == 0)
    {
        globalmax = maxElement;
    }
    return globalmax;
}

// Q-2 you have an unsorted array of length N and ele are in range 1-n there is one element from the range present twice. find the
// repeated element

int findrepeated(int *arr, int n)
{ // array contain [1-n] 1 based index

    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] < 0)
            return i;
        arr[abs(arr[i]) - 1] *= -1;
    }
    return -1;

    /*
    int t = (n * (n + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        {sum += arr[i];}

    int r = abs(t - sum);
    return r;*/
}

// you have an array of size N, and you will get elements in the range [1 - N+2] . no element is repeated find 2 missing numbers

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // cout << maxSumSub(arr, n);
    int res = findrepeated(arr, n);
    cout << arr[res];
    return 0;
}
