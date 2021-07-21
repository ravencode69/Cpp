#include <iostream>
using namespace std;
void finalarray(int input[], int si, int ei, int mid)
{
    int i = si;
    int j = mid + 1;
    int f[500];
    int k = si;
    while (i <= mid && j <= ei)
    {
        if (input[i] < input[j])
        {
            f[k++] = input[i++];
        }
        else
        {
            f[k++] = input[j++];
        }
    }
    while (i <= mid)
    {
        f[k++] = input[i++];
    }
    while (j <= ei)
    {
        f[k++] = input[j++];
    }
    for (i = si; i <= ei; i++)
    {
        input[i] = f[i];
    }
}

void helper(int input[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    helper(input, si, mid);
    helper(input, mid + 1, si);
    finalarray(input, si, ei, mid);
}

void mergeSort(int input[], int size)
{
    int ei = size - 1;

    helper(input, 0, ei);
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
    int l = size;
    mergeSort(arr, l);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}