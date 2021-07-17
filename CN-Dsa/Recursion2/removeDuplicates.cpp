#include <iostream>
#include <string.h>
using namespace std;

void remove(char str[])
{
    if (strlen(str) == 0)
        return;
    remove(str + 1);
    if (str[0] == str[1])
    {
        int i;
        for (i = 1; i != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        str[i] = '\0';
    }
}
int main()
{
    char str[30];
    cin >> str;
    remove(str);
    cout << str;
}