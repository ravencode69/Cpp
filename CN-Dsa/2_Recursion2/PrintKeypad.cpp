#include <iostream>
#include <string>
using namespace std;
string options(int digit)
{
    if (digit == 2)
        return "abc";
    if (digit == 3)
        return "def";
    if (digit == 4)
        return "ghi";
    if (digit == 5)
        return "jkl";
    if (digit == 6)
        return "mno";
    if (digit == 7)
        return "pqrs";
    if (digit == 8)
        return "tuv";
    if (digit == 9)
        return "wxyz";

    return "";
}
void printKeypad(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    int lastDigit = num % 10;
    int smallernumber = num / 10;
    string op = options(lastDigit);
    for (int i = 0; i < op.length(); i++)
    {
        printKeypad(smallernumber, op[i] + output);
    }
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num, "");

    return 0;
}