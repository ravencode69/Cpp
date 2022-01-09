/* Code : Balanced Parenthesis.
For a given a string expression containing only round brackets or parentheses,
check if they are balanced or not. Brackets are said to be balanced
if the bracket which opens last, closes first.*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string e)
{
    stack<char> s1;
    for (int i = 0; e[i] != '\0'; i++) // e[i] !=0
    {
        if (e[i] == '(')
        {

            s1.push(e[i]);
        }
        if (s1.empty() && e[i] == ')')
        {
            return false;
        }
        if (e[i] == ')')
        {
            if (s1.top() == '(')
            {
                s1.pop();
            }
            else
                return false;
        }
    }
    if (s1.empty())
        return true;
    else
        return false;
}
int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
