#include <iostream>
#include <string.h>
using namespace std;

void remove(char str[])
{
    if (strlen(str) == 1)
        return;

    remove(str + 1);
    if (str[0] == str[1])
    {

        for (int i = 1; i <= strlen(str); i++)
        {
            str[i - 1] = str[i];
        }
    }
}
int main()
{
    char str[30];
    cin >> str;

    remove(str);
    cout << str;
}