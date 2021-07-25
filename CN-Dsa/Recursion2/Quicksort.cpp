#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int part(int arr[], int s, int l)

{
    int i = s;
    int j = l;
    int pa = s;
    int pivot = arr[s];
    int count = 0;
    for (int v = s; v <= l; v++)
    {
        if (arr[v] < pivot)
            count++;
    }
    pa = s + count;
    swap(arr, s, pa);
    while (i <= pa && j >= pa)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pa && j > pa)
        {
            swap(arr, i, j);
            i++;
            j--;
        }
    }
    return pa;
}

void q_sort(int arr[], int s, int l)
{
    if (l <= s)
        return;
    int k = part(arr, s, l);
    q_sort(arr, s, k - 1);
    q_sort(arr, k + 1, l);
}

int main()
{
    int length;
    cin >> length;
    int *arr = new int[length];
    cout << "Enter the array elements \n";
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    q_sort(arr, 0, length - 1);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}