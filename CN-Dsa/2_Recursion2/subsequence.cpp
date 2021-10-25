#include <iostream>
#include <string.h>
using namespace std;

int subseq(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string smaller = input.substr(1);
    int sSize = subseq(smaller, output);
    for (int i = 0; i < sSize; i++)
    {
        output[sSize + i] = input[0] + output[i];
    }
    return 2 * sSize;
}

int main()
{
    string input;
    cin >> input;
    string *output = new string[200];
    int d = subseq(input, output);
    for (int i = 0; i < d; i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}