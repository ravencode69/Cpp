#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define all(v) v.begin(), v.end()
#define PB push_back
#define pbac pop_back
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
// Parameters are positive sum is positive
int counts(int ind, int cs, int t, int *arr, int n)
{
    if (ind == n)
    {
        if (cs == t)
        {
            return 1;
        }
        else
            return 0;
    }

    cs += arr[ind];
    int l = counts(ind + 1, cs, t, arr, n);
    cs -= arr[ind];

    // element not included
    int r = counts(ind + 1, cs, t, arr, n);

    return l + r;
}

int main()
{
    OJ;
    OJ;
    int arr[] = {2, 1, 3};
    int n = 3;
    // vi ans; //REMOVED THE DATA STR AS WE NO LONGER NEED TO STORE THE SUBSEQUENCES
    int sum = 2;
    int x = counts(0, 0, sum, arr, n);
    cout << x << endl;

    return 0;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> array(n);
        ll total = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> array[i];
            total += array[i];
        }
        ll find = 1, ctr = 0;
        while (total > 0)
        {
            total -= find;
            ctr += 1;
            find += 1;
        }
        if (total < 0)
            cout << ctr - 1 << endl;
        else
            cout << ctr << endl;
    }

    return 0;
}