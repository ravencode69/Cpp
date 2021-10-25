#include <iostream>
#include <string>
#include <stack>
using namespace std;

#include <stack>
int countBracketReversals(string input)
{
    if (input.length() % 2 != 0)
    {
        return -1;
    }
    stack<int> s;
    int i = 0;
    int ctr = 0;
    while (i < input.length()) //chile lemme just iterate the string real quick
    {
        if (input[i] == '{')
        {
            s.push(input[i]);
            i++;
        }
        if (input[i] == '}')
        {
            if (s.empty())
            {
                s.push(input[i]);
                i++;
            }
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
                i++;
            }
            else if (s.top() != '{')
            {
                s.push(input[i]);
                i++;
            }
        }
    }
    while (!s.empty())
    {
        int c1 = s.top();
        s.pop();
        int c2 = s.top();
        s.pop();
        if (c1 == c2)
        {
            ctr++;
        }
        if (c1 != c2)
        {
            ctr += 2;
        }
    }

    if (ctr > 0)
    {
        return ctr;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}