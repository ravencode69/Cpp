#include <iostream>
using namespace std;
void MergesortN(int arr[], int s, int mid, int l)
{
}

void Mergesort(int arr[], int s, int l)
{
    if (l <= s)
        return;
    int mid = s + l / 2;
    Mergesort(arr, s, mid);
    Mergesort(arr, mid + 1, l);
    MergesortN(arr, s, mid, l);
}

int main()
{
    int arr[30];
    int size;
    cout << " Input size ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int l = size - 1;
    Mergesort(arr, 0, l);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}