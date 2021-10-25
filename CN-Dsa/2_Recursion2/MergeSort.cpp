#include <iostream>
using namespace std;
void merge(int input[], int si, int mid, int li)
{
    int p1 = si, p2 = mid + 1;
    int k = 0;
    int output[100];
    while (p1 <= mid && p2 <= li)
    {
        if (input[p1] < input[p2])
            output[k++] = input[p1++];
        else
            output[k++] = input[p2++];
    }

    while (p1 <= mid)
    {
        output[k++] = input[p1++];
    }
    while (p2 <= li)
    {
        output[k++] = input[p2++];
    }
    int op = 0;
    for (int h = si; h <= li; h++)
    {
        input[h] = output[op++];
    }
}

void mergesort(int arr[], int si, int li)
{
    if (si >= li)
        return;
    else
    {
        int mid = (si + li) / 2;
        mergesort(arr, si, mid);
        mergesort(arr, mid + 1, li);
        merge(arr, si, mid, li);
    }
}
void mergesort(int arr[], int length)
{
    if (length <= 0)
        return;
    int li = length - 1;
    mergesort(arr, 0, li);
}

int main()
{
    int length;
    cin >> length;
    int *arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    mergesort(arr, length);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << "  ";
    }
}