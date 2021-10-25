#include <iostream>
#include <stack>
using namespace std;
void copyStack(stack<int> &original, stack<int> &destination)
{
    if (!original.empty())
    {
        int temp = original.top();
        original.pop();
        copyStack(original, destination);
        destination.push(temp);
    }
}

void reverseStack(stack<int> &input, stack<int> &extra)
{
    while (!input.empty())
    {
        int x = input.top();
        input.pop();
        extra.push(x);
    }

    if (!extra.empty())
    {
        copyStack(extra, input);
    }
}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}