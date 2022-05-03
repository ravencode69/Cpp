// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int a[n];
//         for (int i = 0; i < n; i++)
//             cin >> a[i];

//         int b[n] = {0};
//         int temp = a[n - 1];
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (temp != 0 || a[i] != 0)
//             {
//                 b[i] = 1;
//                 temp = max(temp, a[i]);
//                 temp--;
//             }
//             else
//             {
//                 temp = a[i];
//             }
//         }
//         for (int i = 0; i < n; i++)
//             cout << b[i] << " ";
//         cout << "\n";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int a[n];
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         int out[n] = {0};
//         int temp = a[n - 1];
//         for (int i = n - 1; i >= 0; i--) // cp
//         {
//             if (temp != 0 || a[i] != 0)
//             {
//                 out[i] = 1;
//                 temp = max(temp, a[i]); // cp
//                 temp--;
//             }
//             else
//             {
//                 temp = a[i];
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             cout << out[i] << " ";
//         }
//         cout << endl;
//     }
// }
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int o[n] = {0};

        int temp = v[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (temp != 0 || v[i] != 0)
            {
                o[i] = 1;
                temp = max(temp, v[i]);
                temp--;
            }
            else
            {
                temp = v[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << o[i] << " ";
        }
        cout << endl;
    }
    return 0;
}