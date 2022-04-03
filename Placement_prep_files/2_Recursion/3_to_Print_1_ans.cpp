#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define all(v) v.begin(), v.end()
#define PB push_back
#define popB pop_back
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
bool prints(int index, vi &ans, int cs, int target, int *arr, int n)
{
    if (index == n)
    {
        if (cs == target)
        {
            for (auto x : ans)
                cout << x << " ";
            cout << endl;
            return true;
        }
        else if (cs != target)
            return false;
    }

    ans.PB(arr[index]);
    cs += arr[index];
    if (prints(index + 1, ans, cs, target, arr, n) == true)
    {
        return true;
    }
    ans.popB();
    cs -= arr[index];

    if (prints(index + 1, ans, cs, target, arr, n) == true)
    {
        return true;
    }

    return false;
}

int main()
{
    OJ;
    int arr[] = {2, 1, 1};
    int n = 3;
    vi ans;
    int sum = 2;
    prints(0, ans, 0, sum, arr, n);
    return 0;
}
