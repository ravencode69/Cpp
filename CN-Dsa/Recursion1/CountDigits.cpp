#include <iostream>
using namespace std;
int Dcount(int n)
{

    if (n / 10 == 0)
    {
        return 1;
    }
    return 1 + Dcount(n / 10);
}
int main()
{
    int n;
    cout << "Enter number";
    cin >> n;
    cout << Dcount(n);
}