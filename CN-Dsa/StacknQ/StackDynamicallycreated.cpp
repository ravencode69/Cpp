//If we're creating stack size should not be a constraint that we should be asking our user why? because we now know about the
//dynamic array. let see how to impliment this
#include <iostream>
using namespace std;
class stack
{
private:
    int *array;
    int ci;
    int capacity;

public:
    stack()
    {
        array = new int[capacity];
        ci = 0;
        capacity = 3; //took this value any number that i wanted.
    }

    void push(int data)     //the concept is really simple just when the ci becomes equal to capacity we'll
    {                       //make a new array of double its size and copy the elements from prev  arr then
        if (ci == capacity) // we'll delete the prev array and point the array to the new array and henceforth we'll
        {                   //multiply the capacity by 2
            int *narray = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                narray[i] = array[i];
            }
            delete[] array;
            array = narray;
        }
        ci *= 2;
        array[ci] = data;
        ci++;
    }
    int top()
    {
        return array[ci - 1];
    }
    bool isEmpty()
    {
        return ci == 0;
    }
    int pop()
    {
        if (isEmpty())
        {
            return -1;
            cout << "stack empty";
        }
        ci--;
        return array[ci];
    }
};

int main()
{
    stack s1;
    s1.push(1);
    s1.push(1);
    s1.push(1);
    s1.push(4);
    cout << s1.top();
    s1.push(1);
    s1.push(1);
    s1.push(1);
    s1.push(5);
    cout << s1.top();
    s1.push(1);
    s1.push(1);
    s1.push(1);
    s1.push(6);
    cout << s1.top();
    // cout << s1.pop();
}
