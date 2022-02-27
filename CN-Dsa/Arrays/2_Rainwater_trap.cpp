#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll t, naya, k;
    cin >> t;

    while (t--)
    {
        cin >> naya >> k;

        vector<int> res;
        for (int i = 0; i < k - 3; i++)
        {
            res.push_back(1);
        }
        int n = naya - (k - 3);
        if (n % 2 == 1)
        {
            res.push_back(1);
            res.push_back(n / 2);
            res.push_back(n / 2);
        }
        else
        {
            if (n % 4 != 0)
            {
                res.push_back(n / 2 - 1);
                res.push_back(n / 2 - 1);
                res.push_back(2);
            }
            else if (n % 4 == 0)
            {

                res.push_back(n / 2);
                res.push_back(n / 4);
                res.push_back(n / 4);
            }
        }
        for (int x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
// int main()
// {
//     ll tc, n;
//     cin >> tc;

//     while (tc--)
//     {
//         cin >> n;
//         vector<int> vec(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> vec[i];
//         }

//         vector<int> v1;
//         vector<int> v2;
//         map<int, int> map;
//         for (int i = 0; i < n; i++)
//         {
//             if (map[vec[i]] == 1)
//             {
//                 v2.push_back(vec[i]);
//             }
//             else
//             {
//                 map[vec[i]] = 1;
//                 v1.push_back(vec[i]);
//             }
//         }
//         sort(v1.begin(), v1.end());
//         for (int x : v1)
//         {
//             cout << x << " ";
//         }
//         for (int x : v2)
//         {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }