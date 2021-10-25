#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int small = fib(n - 1);
    int small2 = fib(n - 2);
    return small + small2;
}
int main()
{
    int n;
    cout << "which term";
    cin >> n;
    cout << fib(n);
}