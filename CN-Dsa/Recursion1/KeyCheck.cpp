#include <iostream>
using namespace std;
bool is_key(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    else
    {
        if (arr[0] == key)
            return true;
    }
    bool keyORnot = is_key(arr + 1, size - 1, key);
    return keyORnot;
}

int main()
{
    int array[20];
    int size;
    cout << "Enter size ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    int key;
    cout << "Enter the key ";
    cin >> key;
    if (is_key(array, size, key))
    {
        cout << "True";
    }
    else
    {
        cout << "false";
    }

    return 0;
}