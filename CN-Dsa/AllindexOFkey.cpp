#include <iostream>
using namespace std;

int All(int arr[], int size, int key, int out[])
{
    int ctr;
    if (size == 0)
        return 0;

    int small = All(arr + 1, size - 1, key, out);
}

int main()
{
    int size, key, arr[20], output[20];
    cout << "Input size  ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    All(arr, size, key, output);
}