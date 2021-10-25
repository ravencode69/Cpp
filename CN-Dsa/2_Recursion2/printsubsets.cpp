#include <iostream>
using namespace std;

void helper(int input[], int size, int output[], int os)

{
    if (size == 0)
        for (int i = 0; i < os; i++)
        {
            cout << output[i] << " " << endl;
            return;
        }

    int *includedoutput = new int[os + 1];

    for (int i = 0; i < os; i++)
    {
        includedoutput[i + 1] = output[i];
    }

    includedoutput[os] = input[0];

    helper(input + 1, size - 1, includedoutput, os + 1);
    helper(input + 1, size - 1, output, os);

    return;
}

void printSubsetsOfArray(int input[], int size)
{
    int *output = new int[0];
    int m = 0;
    helper(input, size, output, m);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
