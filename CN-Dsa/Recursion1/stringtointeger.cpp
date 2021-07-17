#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int StoI(char str[], int size)
{
    int p = str[0];
    p = p - 48; //48 is acii code of zero '0'

    if (size = 1)
        return 1;

    int s = StoI(str + 1, size - 1);

    return p * pow(10, size - 1) + s;
}
int main()
{
    char arr[30];
    cin >> arr;
    StoI(arr, strlen(arr));
    cout << arr;
}