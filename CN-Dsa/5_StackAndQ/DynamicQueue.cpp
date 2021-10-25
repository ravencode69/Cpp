#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    T *data;
    int ni;   //next index
    int fi;   //first index
    int cap;  //capacity of the array as given by the user
    int size; //current size of Q.
public:
    Queue(int dsize)
    {
        data = new T[dsize];
        cap = dsize;
        fi = -1;
        ni = 0;
        size = 0;
    }
    int givesize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int front()
    {

        if (isEmpty())
        {
            cout << "Q is EMPTY";
            return 0;
        }
        return data[fi];
    }
    void enqueue(T x)
    {
        if (size == cap)
        {
            T *ndata = new T[2 * cap];
            int j = 0;
            for (int i = fi; i < cap; i++)
            {
                ndata[j] = data[i];
                j++;
            }
            for (int i = 0; i < fi; i++)
            {
                ndata[j] = data[i];
                j++;
            }
            delete[] data;
            data = ndata;
            fi = 0;
            ni = cap;
            cap *= 2;
        }

        data[ni] = x;
        ni = (ni + 1) % cap;
        if (fi == -1)
        {
            fi = 0;
        }
        size++;
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Q is EMPTY";
            return 0;
        }
        T deletedElement = data[fi];
        fi = (fi + 1) % cap;
        size--;
        if (size == 0)
        {
            fi = -1;
            ni = 0;
        }
        return deletedElement;
    }
};

int main()
{
    Queue<int> q1(5);

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(30);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6); // gives Q is FULL message
    cout << "\t" << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.front() << endl;
    cout << q1.givesize() << endl;
    cout << q1.isEmpty() << endl;
}