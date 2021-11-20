#include <iostream>
using namespace std;

#define M 1000000007
int balancedBTs(int n)
{
    // Write your code here
    if (n <= 1)
        return 1;

    int a = balancedBTs(n - 1);
    int b = balancedBTs(n - 2);

    int ans1 = (int)(((long)(a)*a) % M);
    int ans2 = (int)((2 * (long)(a)*b) % M);
    int fa = (ans1 + ans2) % M;
    return fa;
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}