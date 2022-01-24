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

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        unordered_map<int, vector<int>> map;

        int n = s.size();
        fr(n)
        {
            auto e = s[i];
            if (isupper(e))
                map[0].push_back(i);
            if (islower(e))
                map[1].push_back(i);
            if (isdigit(e))
                map[2].push_back(i);
        }
        if (map.size() == 1)
        {
            if (map.begin()->first == 0)
                s[0] = '1', s[2] = 'a';
            if (map.begin()->first == 1)
                s[0] = '1', s[2] = 'A';
            if (map.begin()->first == 2)
                s[0] = 'A', s[2] = 'a';
        }

        if (map.size() == 2)
        {
            auto compare = [](auto i, auto j)
            { return i.second.size() < j.second.size(); };
            auto i = max_element(map.begin(), map.end(), compare)->second[0];

            if (map[0].empty())
                s[i] = 'A';
            if (map[1].empty())
                s[i] = 'a';
            if (map[2].empty())
                s[i] = '1';
        }
        cout << s << endl;
    }
    return 0;
}