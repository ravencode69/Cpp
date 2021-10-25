#include <iostream>
using namespace std;

int exponent(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int small = exponent(m, n - 1);
    int output = m * small;
    return output;
}

int main()
{
    int m, n;
    cout << "Enter number and its corrosponding exponent ";
    cin >> m >> n;
    cout << exponent(m, n);
}