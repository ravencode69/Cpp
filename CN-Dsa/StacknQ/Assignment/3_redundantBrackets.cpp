//Good Question !!

#include <iostream>
#include <string>
#include <stack>
using namespace std;

#include <stack>
bool checkRedundantBrackets(string input)
{
    stack<char> s1;
    int i = 0;

    while (input[i] != 0)
    {
        int count = 0;

        if (input[i] == ')')
        {
            while (s1.top() != '(')
            {
                s1.pop();
                count++;
            }

            s1.pop();

            if (count == 1 || count == 0)
            {
                return true;
            }
            i++;
        }
        else
        {
            s1.push(input[i]);
            i++;
        }
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}