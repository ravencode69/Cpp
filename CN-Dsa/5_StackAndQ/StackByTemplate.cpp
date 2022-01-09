#include <iostream>
using namespace std;

/*template help us to create a stack of any data type*/ template <typename T> // Template defination

class stack
{
private:
    T *array;
    int ci;
    int capacity;

public:
    stack()
    {
        array = new T[capacity];
        ci = 0;
        capacity = 3; // took this value any number that i wanted.
    }

    void push(int data)     // the concept is really simple just when the ci becomes equal to capacity we'll
    {                       // make a new array of double its size and copy the elements from prev  arr then
        if (ci == capacity) // we'll delete the prev array and point the array to the new array and henceforth we'll
        {                   // multiply the capacity by 2
            T *narray = new T[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                narray[i] = array[i];
            }
            delete[] array;
            array = narray;
            ci *= 2;
        }

        array[ci] = data;
        ci++;
    }
    T top()
    {
        if (isEmpty())
        {
            return 0;
            cout << "stack empty";
        }
        return array[ci - 1];
    }
    bool isEmpty()
    {
        return ci == 0;
    }
    T pop()
    {
        if (isEmpty())
        {
            return 0;
            cout << "stack empty";
        }
        ci--;
        return array[ci];
    }
};

int main()
{
    stack<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');
    cout << s1.top();
    s1.push('e');
    s1.push('f');
    s1.push('g');
    s1.push('h');
    cout << s1.top();
    s1.push('i');
    s1.push('j');
    s1.push('k');
    s1.push('l');
    cout << s1.top();
    cout << s1.pop();
}
