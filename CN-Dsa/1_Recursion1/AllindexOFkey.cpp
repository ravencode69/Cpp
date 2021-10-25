#include <iostream>
using namespace std;

int All(int arr[], int size, int key, int out[])
{

    if (size == 0)
        return 0;

    int small = All(arr + 1, size - 1, key, out);

    if (arr[0] == key)
    {
        for (int i = 0; i < size; i++)
        {
            out[i + 1] = out[i] + 1;
        }
        out[0] = 0;
        small = small + 1;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            out[i] = out[i] + 1;
        }
    }
    return small;
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
    cin >> key;
    cout << All(arr, size, key, output);
    int x = All(arr, size, key, output);
    for (int i = 0; i < x; i++)
    {
        cout << output[i];
    }
    return 0;
}