#include <iostream>
#include <string.h>
using namespace std;

void replacePiHelper(char str[], int start, int size)
{
    if (str[start] == '\0' || str[start + 1] == '\0')
    {
        return;

        replacePiHelper(str, start + 1, size - 1);
    }

    else if (str[start] == 'p' && str[start + 1] == 'i')
    {
        for (int i = start + 2; i <= size; i++)
        {
            char temp = str[i + 1];
            str[i + 1] = str[i];
            str[i + 2] = temp;
        }
        size = size + 1;
        str[size] = '\0';
        str[start] = '3';
        str[start + 1] = '.';
        str[start + 2] = '1';
        str[start + 3] = '4';
        replacePiHelper(str, start + 4, size);
    }
}

int main()
{
    char arr[30];
    cin >> arr;
    replacePiHelper(arr, 0, strlen(arr));
    cout << arr;
}