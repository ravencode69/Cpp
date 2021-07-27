#include <iostream>

using namespace std;

int binarySearch(int input[], int l, int h, int x)
{
    if (h < l)
    {
        return -1;
    }
    int m = (l + h) / 2;
    if (input[m] == x)
        return m;

    if (x > input[m])
    {
        l = m + 1;
        return binarySearch(input, l, h, x);
    }
    if (x < input[m])
    {
        h = m - 1;
        return binarySearch(input, l, h, x);
    }
}
int binarySearch(int input[], int size, int element)
{
    int last = size - 1;
    binarySearch(input, 0, last, element);
}

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}
