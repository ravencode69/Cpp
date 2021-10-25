#include <iostream>
using namespace std;

int count(int N)
{

    if (N < 10)
    {
        if (N == 0)
            return 1;
        else
            return 0;
    }
    if (N % 10 == 0)
        return 1 + count(N / 10);
    else
        return count(N / 10);
}

int main()
{
    int N;
    cout << "Number ";
    cin >> N;
    cout << count(N);
}