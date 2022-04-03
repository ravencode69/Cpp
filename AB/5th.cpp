#include <bits/stdc++.h>
using namespace std;

#define popB pop_back
typedef vector<int> vi;
typedef pair<int, int> pii;
#define all(v) v.begin(), v.end()
#define PB push_back
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

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int idx = min(k, n - 1);
        cout << arr[idx] << endl;
    }
    return 0;
}