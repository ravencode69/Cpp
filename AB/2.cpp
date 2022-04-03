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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string word;
        cin >> word;
        vector<vector<int>> ans;

        for (int i = n - 1; i >= 0; i--)
        {
            if (word[i] == '0')
            {
                int x = i + 1;
                for (int j = 0; j <= i; j++)
                {
                    word[j] == '1' ? word[j] = '0' : word[j] = '1';
                }
                ans.push_back({1ll, x});
            }
        }
        int actual = ans.size();
        cout << actual << endl;
        for (vector<int> x : ans)
            cout << x[0] << " " << x[1] << endl;
    }
    return 0;
}