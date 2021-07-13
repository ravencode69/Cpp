#include <iostream>
using namespace std;
int factorial(int n)
{
    cout << n;
    int smalloutput = factorial(n - 1);
    return n * smalloutput;
}
int main()
{
    int n;
    cin >> n;
    factorial(n);
}