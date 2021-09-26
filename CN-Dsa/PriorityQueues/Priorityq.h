
#include <vector>
using namespace std;
class priorityq
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size(); //size of pq i.e number of elements
    }
    int getMin()
    {
        if (isEmpty())
        {
            return 0; // indicating the pq is empty
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childindex = pq.size() - 1;
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] < pq[parentindex])
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

    int removeMin()
    {
        if (isEmpty())
        {
            return 0; // indicating the pq is empty
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];

        pq.pop_back();

        //down heapify
        int parentindex = 0;
        int lci = 2 * parentindex + 1;
        int rci = 2 * parentindex + 2;

        while (lci < pq.size())
        {
            int minindex = parentindex;

            if (pq[minindex] > pq[lci])
            {
                minindex = lci;
            }
            if (rci < pq.size() && pq[minindex] > pq[rci])
            {
                minindex = rci;
            }
            if (minindex == parentindex)
            {
                break;
            }

            //swapping
            int temp = pq[minindex];
            pq[minindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = minindex;
            lci = 2 * parentindex + 1;
            rci = 2 * parentindex + 2;
        }

        return ans;
    }
};