#include <iostream>
#include <string.h>
using namespace std;

bool helper(char arr[], int start, int end)
{
    if (end < start)
        return true;
    if (arr[start] != arr[end])
    {
        return false;
    }
    bool small = helper(arr, start + 1, end - 1);
    return small;
}

bool CheckP(char arr[])
{
    int end = strlen(arr) - 1;
    return helper(arr, 0, end);
}

int main()
{
    char arr[30];
    cin >> arr;
    if (CheckP(arr) == true)
        cout << "true";
    else
        cout << "false";
    return 0;
}