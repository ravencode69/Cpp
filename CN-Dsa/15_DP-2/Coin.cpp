/*Ways To Make Coin Change
Send Feedback
For the given infinite supply of coins of each of denominations,
 D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W,
 in which you can make the change for Value V using coins of denominations D.*/

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    if (numDenominations <= 0 && value > 0)
        return 0;

    int ans1 = countWaysToMakeChange(denominations, numDenominations - 1, value);
    int ans2 = countWaysToMakeChange(denominations, numDenominations, value - denominations[numDenominations - 1]);
    return ans1 + ans2;
}

// MEMOIZATION
int countWaysToMakeChange(int denominations[], int numDenominations, int value, int **arr)
{
    if (value == 0)
        return 1;

    if (numDenominations <= 0 && value > 0)
        return 0;
    if (value < 0)
    {
        return 0;
    }
    if (arr[numDenominations][value] != -1)
        return arr[numDenominations][value];

    int ans1 = countWaysToMakeChange(denominations, numDenominations - 1, value, arr);
    int ans2 = countWaysToMakeChange(denominations, numDenominations, value - denominations[numDenominations - 1], arr);

    arr[numDenominations][value] = ans1 + ans2;

    return arr[numDenominations][value];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{

    int **arr = new int *[numDenominations + 1];
    for (int i = 0; i <= numDenominations; i++)
    {
        arr[i] = new int[value + 1];
        for (int j = 0; j <= value; j++)
        {
            arr[i][j] = -1;
        }
    }
    countWaysToMakeChange(denominations, numDenominations, value, arr);
}

// D Y N A M I C P R O G R A M M I N G
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **arr = new int *[numDenominations];

    for (int i = 0; i < numDenominations; i++)
        arr[i][0] = 1;

    for (int j = 1; j < value; j++)
        arr[0][j] = 0;
}
