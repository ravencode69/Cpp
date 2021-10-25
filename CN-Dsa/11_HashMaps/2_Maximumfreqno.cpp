#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    int maxmap = map[arr[0]];
    int max = arr[0];
    int j = 1;
    while (j < n)
    {
        if (maxmap < map[arr[j]])
        {
            maxmap = map[arr[j]];
            max = arr[j];
        }
        j++;
    }
    return max;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
