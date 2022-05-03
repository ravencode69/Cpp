#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;

        if (n % 2 > 0)
        {
            v.push_back(1);
            v.push_back(n / 2);
            v.push_back(n / 2);
        }
        else
        {
            if (n % 4 != 0)
            {
                v.push_back(2);
                v.push_back((n / 2) - 1);
                v.push_back((n / 2) - 1);
            }
            else
            {
                v.push_back(n / 2);
                v.push_back(n / 4);
                v.push_back(n / 4);
            }
        }

        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
}