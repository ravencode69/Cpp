#include <bits/stdc++.h>
#include <numeric>
using namespace std;
/*
2 ≤ T, N ≤ 105, 1 ≤ Q ≤ N, 1 ≤ A[i] ≤ 105
1 ≤ L, R ≤ N and L ≤ R
Sum of N over all the test cases will be less than or equal to 106.

*/

const int N = 1e5 + 10;

int main()
{
    int te;
    cin >> te;

    while (te--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n + 10];
        int pf[n + 10];
        int sf[n + 10];

        pf[0] = sf[n + 1] = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = n; i >= 1; i--)
        {
            sf[i] = __gcd(arr[i], sf[i + 1]);
        }
        for (int i = 1; i <= n; i++)
        {
            pf[i] = __gcd(pf[i - 1], arr[i]);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int ans = __gcd(pf[l - 1], sf[r + 1]);
            cout << ans << endl;
        }
    }
}
