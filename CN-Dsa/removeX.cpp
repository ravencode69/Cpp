#include <iostream>
#include <string.h>
using namespace std;

void rex(char str[], int size, int start)
{
    if (str[start] == '\0')
    {
        return;
    }
    if (str[start] == 'x')
    {
        for (int i = start; i < size; i++)
        {
            str[i] = str[i + 1];
        }
        size = size - 1;
    }
    else
    {
        start++;
    }
    rex(str, size, start);
}

int main()
{

    char str[30];
    cin >> str;
    rex(str, strlen(str), 0);
    cout << str;
    return 0;
}