#include <iostream>
using namespace std;

int Lindex(int arr[], int size, int x)
{
    if (size == 0)
    {
        return -1;
    }
    int small = Lindex(arr + 1, size - 1, x);
    return (small != -1) ? small = small + 1 : (arr[0] = x) ? 0
                                                            : -1;
}

int main()
{
    int x, arr[20], size;
    cout << "Size ?? ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Element ?? ";
    cin >> x;
    cout << Lindex(arr, size, x);
}