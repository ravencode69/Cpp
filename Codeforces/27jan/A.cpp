#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a2[i];
    }
    for (int i = 0; i < a2.size(); ++i)
    {
        if (a2[i] > a1[i])
        {
            swap(a2[i], a1[i]);
        }
    }
    int x = *max_element(a1.begin(), a1.end());
    int y = *max_element(a2.begin(), a2.end());
    cout << x * y << endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
