#include <bits/stdc++.h>
using namespace std;

#define ll long long

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