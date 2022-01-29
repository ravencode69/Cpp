#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll x = a[n - 1];
        ll count = 0;
        ll length = 1;
        ll j = n - 2;
        while (j >= 0)
        {
            while (j >= 0 && a[j] == x)
            {
                length++;
                j--;
            }
            if (j < 0)
                break;
            count++;
            j = j - length;
            length *= 2;
        }
        cout << count << endl;
    }
    return 0;
}