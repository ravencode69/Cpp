#include <bits/stdc++.h>
using namespace std;

void heapSort(int pq[], int n)
{

    for (int i = 0; i < n; i++)
    {

        int childindex = i;
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] < pq[parentindex])
            {
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }

    int size = n;
    while (size > 0)
    {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;
        size--;
        int parentindex = 0;
        int lci = 2 * parentindex + 1;
        int rci = 2 * parentindex + 2;

        while (lci < size)
        {
            int minindex = parentindex;

            if (pq[minindex] > pq[lci])
            {
                minindex = lci;
            }
            if (rci < size && pq[minindex] > pq[rci])
            {
                minindex = rci;
            }
            if (minindex == parentindex)
            {
                break;
            }

            //swapping
            int temp = pq[minindex];
            pq[minindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = minindex;
            lci = 2 * parentindex + 1;
            rci = 2 * parentindex + 2;
        }
    }
}
int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}