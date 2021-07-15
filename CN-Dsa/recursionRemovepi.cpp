#include <iostream>
#include <string.h>
using namespace std;

void replacePiHelper(char str[], int start)
{
    if (str[start] == '\0' || str[start + 1] == '\0')
    {
        return;
    }
    replacePiHelper(str, start + 1);

    if (str[start] == 'p' && str[start + 1] == 'i')
    {
        for (int i = strlen(str); i >= start + 2; i--)
        {
            str[i + 2] = str[i];
        }

        str[start] = '3';
        str[start + 1] = '.';
        str[start + 2] = '1';
        str[start + 3] = '4';
    }
}

int main()
{
    char arr[30], out[30];
    cin >> arr;
    replacePiHelper(arr, 0);
    cout << out;
}