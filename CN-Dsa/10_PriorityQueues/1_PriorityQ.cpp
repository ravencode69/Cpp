#include <iostream> //TC : O(n log n) SC: O(n)
#include "Priorityq.h"
using namespace std;

int main()
{
    priorityq p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(111);
    p.insert(500);
    cout << p.getSize() << endl;
    cout << p.getMin() << endl;
    while (!p.isEmpty())
    {
        cout << p.removeMin() << endl;
    }
    return 0;
}
