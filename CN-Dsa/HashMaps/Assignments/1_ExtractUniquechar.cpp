#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char *uniqueChar(string str)
{
    int len = str.length();
    if (len == 0)
    {
        char *ans = new char[1];
        ans[0] = '\0';
        return ans;
    }
    char *ans = new char[len + 1];
    unordered_map<char, bool> hm;
    int i = 0;
    for (int currIndex = 0; currIndex < len; currIndex++)
    {
        char currChar = str[currIndex];
        if (hm.count(currChar) == 0)
        {
            hm[currChar] = true;
            ans[i++] = currChar;
        }
    }
    ans[i] = '\0';
    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}