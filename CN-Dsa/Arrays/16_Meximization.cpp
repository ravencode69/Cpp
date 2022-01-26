#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n);
        vector<int> out, out2;
        map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            cin >> ans[i];

            if (map[ans[i]] == 1)
            {
                out2.push_back(ans[i]);
            }
            else
            {
                out.push_back(ans[i]);
                map[ans[i]]++;
            }
        }

        sort(out.begin(), out.end());
        for (int i = 0; i < out.size(); i++)
            cout << out[i] << " ";
        for (int i = 0; i < out2.size(); i++)
            cout << out2[i] << " ";
        cout << endl;
    }
}