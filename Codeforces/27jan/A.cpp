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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define mod 1000000007
#define endl '\n'
#define vi vector<int>
#define vi2 vector<vector<int>>
#define pb push_back
#define ppb pop_back
#define pi pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define mi map<int, int>
#define all(x) x.begin(), x.end()
#define sortall(a) sort(all(a))
#define print(a)                       \
    for (int i = 0; i < a.size(); i++) \
    {                                  \
        cout << a[i] << ' ';           \
    }

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif

void _print(int t)
{
    cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/*--------------------------------------------------------------------------------------------------*/
int ceil1(int a, int b) { return (a + b - 1) / b; }
int mod_power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2 == 0)
        {
            a = ((a % mod) * (a % mod)) % mod;
            b /= 2;
        }
        else
        {
            res = ((res % mod) * (a % mod)) % mod;
            b--;
        }
    }
    return res;
}
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2 == 0)
        {
            a = ((a) * (a));
            b /= 2;
        }
        else
        {
            res = ((res) * (a));
            b--;
        }
    }
    return res;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
vi primes(int n)
{
    vi arr(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == true)
        {
            for (int j = i + i; j < n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    vi res;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == true)
        {
            res.push_back(i);
        }
    }
    return res;
}
int add(int a, int b)
{
    int x = ((a % mod) + (b % mod)) % mod;
    return x;
}
int subtract(int a, int b)
{
    int x = ((a % mod) - (b % mod)) % mod;
    return x;
}
int multiply(int a, int b)
{
    int x = ((a % mod) * (b % mod)) % mod;
    return x;
}
int division(int a, int b)
{
    int x = ((a % mod) * (mod_power(b, mod - 2) + mod) % mod) % mod;
    return x;
}
/*--------------------------------------------------------------------------------------------------*/

void solve()
{

    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ele = arr[n - 1];
    int i = n - 2;
    int op = 0;
    int effect = 1;
    while (i >= 0)
    {
        int flag = 1;
        for (int j = 0; j < effect; j++)
        {
            debug(i);
            if (i < 0)
            {
                break;
            }
            if (i >= 0 && arr[i] != ele && flag)
            {
                op++;
                flag = 0;
            }
            i--;
        }
        effect *= 2;
    }
    cout << op << endl;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}