#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q1;
    q1.push(91);
    q1.push(92);
    q1.push(93);
    q1.push(94);
    q1.push(95);
    q1.push(96);

    cout << q1.front() << endl;
    cout << q1.size() << endl;
    q1.pop();
    cout << q1.size() << endl;
    cout << q1.empty();
}