#include <iostream>
#include <string.h>
using namespace std;

void rec(char str[], char r, char x)
{
    if (strlen(str) == 0)
        return;
    if (str[0] == x)
        str[0] = r;
    rec(str + 1, r, x);
}

int main()
{
    char r, x, str[30];
    cin >> str;
    cout << "Remove ";
    cin >> x;
    cout << "with ";
    cin >> r;
    rec(str, r, x);
    cout << str;
}