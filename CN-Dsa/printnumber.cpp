#include <iostream>
using namespace std;

int Print(int a)
{
    cout << a;
    if (a == 0)
    {
        return 0;
    }
    int small = Print(a - 1);
}

int main()
{
    int a;
    cin >> a;
    Print(a);
}