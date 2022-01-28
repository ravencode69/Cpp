// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> ans(n);
//         vector<int> out, out2;
//         map<int, int> map;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> ans[i];

//             if (map[ans[i]] == 1)
//             {
//                 out2.push_back(ans[i]);
//             }
//             else
//             {
//                 out.push_back(ans[i]);
//                 map[ans[i]]++;
//             }
//         }

//         sort(out.begin(), out.end());
//         for (int i = 0; i < out.size(); i++)
//             cout << out[i] << " ";
//         for (int i = 0; i < out2.size(); i++)
//             cout << out2[i] << " ";
//         cout << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v, v2;
        vector<int> inp(n);
        map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            cin >> inp[i];
            if (map[inp[i]] == 1)
            {
                v2.push_back(inp[i]);
            }
            else
            {
                v.push_back(inp[i]);
                map[inp[i]]++;
            }
        }
        sort(v.begin(), v.end());
        for (int x : v)
        {
            cout << x << " ";
        }
        for (int x : v2)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
