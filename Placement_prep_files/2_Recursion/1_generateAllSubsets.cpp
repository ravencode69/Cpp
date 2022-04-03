#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
void helper(vector<int> &nums, vector<vector<int>> &store, vector<int> &ans, int si)
{
    if (si == nums.size())
    {
        store.push_back(ans);
        return;
    }
    //[3,1,2]

    ans.push_back(nums[si]);

    helper(nums, store, ans, si + 1); //[3] [31] [312]

    ans.pop_back(); // ans=[312]--->[31]

    helper(nums, store, ans, si + 1); // h(nums, str,31,3)
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> eachsubset;
    vector<vector<int>> answer;

    helper(nums, answer, eachsubset, 0);
    return answer;
}
int main()
{
    OJ;

    vector<int> nums(4);
    for (int x : nums)
        cin >> x;
    return 0;
}