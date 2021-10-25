#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeD(vector<int> &v)
{
    unordered_map<int, bool> map;
    vector<int> op;

    for (int i = 0; i < v.size(); i++)
    {
        if (map.count(v[i]) > 0)
        {
            continue;
        }
        else
            map[v[i]] = "true";
        op.push_back(v[i]);
    }
    return op;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    v = removeD(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}