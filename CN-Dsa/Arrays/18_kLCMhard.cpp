// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         vector<int> out;
//         int kitnebaarek = k - 3;

//         for (int i = 0; i < kitnebaarek; i++)
//         {
//             out.push_back(1);
//         }
//         n = n - kitnebaarek;
//         if (n % 2 == 0)
//         {
//             if (n % 4 == 0)
//             {
//                 out.push_back(n / 2);
//                 out.push_back(n / 4);
//                 out.push_back(n / 4);
//             }
//             else
//             {
//                 out.push_back(n / 2 - 1);
//                 out.push_back(n / 2 - 1);
//                 out.push_back(2);
//             }
//         }
//         else
//         {
//             out.push_back(n / 2);
//             out.push_back(n / 2);
//             out.push_back(1);
//         }
//         for (int x : out)
//             cout << x << " ";
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
        int n, k;

        cin >> n >> k;

        vector<int> vec;

        int kitnebaarek = k - 3;

        for (int i = 0; i < kitnebaarek; i++)
        {
            vec.push_back(1);
        }

        n = n - kitnebaarek;

        if (n % 2 == 0)
        {
            if (n % 4 == 0)
            {
                vec.push_back(n / 2);
                vec.push_back(n / 4);
                vec.push_back(n / 4);
            }
            else
            {
                vec.push_back(n / 2 - 1);
                vec.push_back(n / 2 - 1);
                vec.push_back(2);
            }
        }
        else
        {

            vec.push_back(n / 2);
            vec.push_back(n / 2);
            vec.push_back(1);
        }

        for (int x : vec)

            cout << x << " ";
        cout << endl;
    }
}