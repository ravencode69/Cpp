#include <bits/stdc++.h>
using namespace std;

void menu()
{
    cout << "\n\t\tMENU :" << endl;
    cout << "***************************";
    cout << "\n1. Display The array: \n";
    cout << "\n2. Heap Sort Ascending Order: \n";
    cout << "\n3. Extract Largest Element: \n";
    cout << "\n4. Insert Element: \n";
    cout << "\n5. Delete Element: \n";
}
int deleteElement(vector<int> &arr, int n, int x)
{

    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            break;

    if (i < n)
    {

        n = n - 1;
        for (int j = i; j < n; j++)
            arr[j] = arr[j + 1];
    }

    return n;
}

int findlargestelement(vector<int> &a, int n)
{
    int largest = a[0];
    for (int i = 0; i < n; i++)
    {
        if (largest < a[i])
        {
            largest = a[i];
        }
    }
    return largest;
}
static void Insert(vector<int> &v, int *n)
{
    int i, j;

    for (i = *n - 1; i >= 0; i--)
    {
        if (v[i] % 2 == 1)
        {
            (*n)++;
            int d = v[i] * 2;
            for (j = *n - 1; j >= i + 1; j--)
            {
                v[j + 1] = v[j];
            }
            v[i + 1] = d;
        }
    }
}

void heapify(vector<int> &a, int n, int i)
{
    int maxIdx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[maxIdx])
    {
        maxIdx = l;
    }
    if (r < n && a[r] > a[maxIdx])
    {
        maxIdx = r;
    }
    if (maxIdx != i)
    {
        swap(a[i], a[maxIdx]);
        heapify(a, n, maxIdx);
    }
}

void heapSort(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void print_array(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n, choice, index;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    do
    {
        menu();
        ;

        cout << "Enter Your choice ... " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            print_array(a, n);
            break;
        case 2:
            heapSort(a);
            print_array(a, n);
            break;
        case 3:
            cout << findlargestelement(a, n) << endl;
            break;
        case 4:
            cout << "Enter the index of the element to be inserted: " << endl;
            cin >> index;
            cout << "Enter the elment to be inserted" << endl;
            cin >> a[index];
            Insert(a, &index);
            print_array(a, n);
            break;
        case 5:
            cout << "Enter the index of the element to be deleted: " << endl;
            cin >> index;
            int x;
            cin >> x;
            n = deleteElement(a, n, x);
            print_array(a, n);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 6);
    return 0;
}