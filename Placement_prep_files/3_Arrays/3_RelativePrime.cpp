#include <bits/stdc++.h>
using namespace std;

//{
#define cel(n, k) ((n - 1) / k + 1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//}

ll ls, r;

int main()
{

    cin >> ls >> r;

    cout << "YES"
         << "\n";
    for (int i = 0; i < r - ls + 1; i = i + 2)
    {
        cout << ls + i << " " << ls + i + 1 << "\n";
    }
    return 0;
}