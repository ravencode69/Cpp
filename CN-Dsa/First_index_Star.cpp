#include <iostream>
using namespace std;

int Firstindex(int arr[], int size, int key)
{

    if (size < 1)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return 0;
    }
    int small = Firstindex(arr + 1, size - 1, key);
    if (small != -1)
    {
        return small + 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int key;
    int size, arr[20];
    cout << "Size";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key";
    cin >> key;
    cout << Firstindex(arr, size, key);
}