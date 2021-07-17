#include <iostream>
using namespace std;

int mul(int M, int N)
{
    if (M == 0 || N == 0)
        return 0;
    int small = mul(M, N - 1) + M;
    return small;
}

int main()
{
    int M, N;
    cin >> M >> N;
    cout << mul(M, N);
}