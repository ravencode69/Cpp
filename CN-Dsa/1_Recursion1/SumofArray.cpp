#include <iostream>
using namespace std;

int Sum(int arr[], int s)
{
    if (s == 0)
    {
        return 0;
    }
    if (s == 1)
    {
        return arr[0];
    }
    int small = Sum(arr + 1, s - 1);
    int output = small + arr[0];
    return output;
}
int main()
{
    int size;
    cin >> size;
    int arr[20];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << Sum(arr, size);
    return 0;
}