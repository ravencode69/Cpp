#include <iostream>
#include <string.h>
using namespace std;

void Res(char arr[], int start)
{
    if (arr[start] == '\0' || arr[start + 1] == '\0')
        return;
    if (arr[start] == arr[start + 1])
    {
        int i;
        for (i = strlen(arr); i >= start + 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = '*';
    }
    Res(arr, start + 1);
}

int main()
{
    char arr[30];
    cin >> arr;
    Res(arr, 0);
    cout << arr;
}