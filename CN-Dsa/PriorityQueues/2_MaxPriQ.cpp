#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element);
        int childindex = pq.size() - 1;

        while (childindex > 0)
        {

            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] > pq[parentindex])
            {
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }
    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getMax()
    {
        // Implement the getMax() function here
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return 0; // indicating the pq is empty
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentindex = 0;
        int lci = 2 * parentindex + 1;
        int rci = 2 * parentindex + 2;

        while (lci < pq.size())
        {

            int maxindex = parentindex;

            if (pq[maxindex] < pq[lci])
            {
                maxindex = lci;
            }
            if (rci < pq.size() && pq[maxindex] < pq[rci])
            {
                maxindex = rci;
            }
            if (maxindex == parentindex)
            {
                break;
            }
            int temp = pq[maxindex];
            pq[maxindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = maxindex;
            lci = 2 * parentindex + 1;
            rci = 2 * parentindex + 2;
        }
        return ans;
    }
};
int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMax
            cout << pq.getMax() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMax() << "\n";
            break;
        case 4: // size
            cout << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");
        default:
            return 0;
        }

        cin >> choice;
    }
}