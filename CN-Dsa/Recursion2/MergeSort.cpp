#include <iostream>
using namespace std;
void merging(int input[], int low, int mid, int high)
{

    int b[200];
    int l1 = low, l2 = mid + 1, i = 0;
    while (l1 <= mid && l2 <= high)
    {
        if (input[l1] <= input[l2])
            b[i++] = input[l1++];
        else
            b[i++] = input[l2++];
    } // end while loop here
    while (l1 <= mid)
    {
        b[i++] = input[l1++];
    }

    while (l2 <= high)
    {
        b[i++] = input[l2++];
    }

    int j = 0;
    for (i = low; i <= high; i++)
        input[i] = b[j++];

    //   }   dont end it here
}
void mergeSort1(int input[], int first, int last)
{

    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort1(input, first, mid);
        mergeSort1(input, mid + 1, last);
        merging(input, first, mid, last);
    }
    else
    {
        return;
    }
}
void mergeSort(int input[], int length)
{
    if (length <= 0)
    {
        return;
    }
    mergeSort1(input, 0, length - 1);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}