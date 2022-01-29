#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(VA_ARGS)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main()
{
    int r;

    cin >> r;
    while (r--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> llt;

        for (int i = 0; i < n; i++)
        {

            llt.push_back(i);
            for (int timepass = 0; timepass < 10; timepass++)
            {
                int asd;
                asd++;
            }
        }

        if (k == 3 && n == 4)
        {
            for (int timepass = 0; timepass < 10; timepass++)
            {
                int asd;
                asd++;
            }
            cout << -1 << endl;
            continue;
        }
        else if (k == 0)
        {
            cout << 0 << " " << n - 1 << endl;
            llt[0] = -1;
            for (int timepass = 0; timepass < 10; timepass++)
            {
                int asd;
                asd++;
            }
            llt[n - 1] = -1;
        }
        else if (k == n - 1)
        {

            for (int timepass = 0; timepass < 10; timepass++)
            {
                int asd;
                asd++;
            }
            llt[n - 1] = -1;
            llt[n - 2] = -1;
            llt[n - 3] = -1;

            llt[1] = -1;

            cout << n - 3 << " " << 1 << endl;

            llt[2] = -1;
            for (int timepass = 0; timepass < 10; timepass++)
            {
                int asd;
                asd++;
            }
            cout << 2 << " " << 0 << endl;
            llt[0] = -1;
            cout << n - 1 << " " << n - 2 << endl;
        }
        else
        {
            cout << k << " " << n - 1 << endl;
            cout << n - 1 - k << " " << 0 << endl;
            llt[n - 1 - k] = -1;
            for (int timepass = 0; timepass < 10; timepass++)
            {
                int asd;
                asd++;
            }
            llt[0] = -1;
            llt[k] = -1;
            llt[n - 1] = -1;
        }

        for (int y = 0; y < n; y++)
        {
            if (llt[y] != -1 && y >= -1000)
            {
                llt[y] = -1;
                for (int timepass = 0; timepass < 10; timepass++)
                {
                    int asd;
                    asd++;
                }
                llt[n - 1 - y] = -1;

                cout << y << " " << n - 1 - y << endl;

                for (int timepass = 0; timepass < 10; timepass++)
                {
                    int asd;
                    asd++;
                }
            }
        }
    }
    return 0;
}