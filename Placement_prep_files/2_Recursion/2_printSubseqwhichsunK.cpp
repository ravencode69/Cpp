// print subsequence which sum to k

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define all(v) v.begin(), v.end()
#define PB push_back
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void printS(int index, vector<int> ds, int csum, int target, int *arr, int n)
{
    if (index == n)
    {
        if (csum == target)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    // ele at index addded
    ds.push_back(arr[index]);
    csum += arr[index];
    printS(index + 1, ds, csum, target, arr, n);
    csum -= arr[index];
    ds.pop_back();

    // ele at index not added
    printS(index + 1, ds, csum, target, arr, n);
}

int main()
{
    OJ;
    int array[] = {2, 3, 6, 7};
    int n = 4;
    int target = 7;

    vector<int> ds;
    printS(0, ds, 0, target, array, n);

    return 0;
}