//Going forward we will be using either LL or array to create data structures but we'll put certain restrictions on them so that user utilizes it
//in the way we wanted it to be to put restrictions on a data member we know we could use classes and we'll do the same
//in this program i'll demonstrate how to create a stack by using Array

#include <iostream>
using namespace std;

class Stack
{
    int *array;
    int ci;       //currentIndex of the array
    int capacity; //size of the array

public:
    Stack(int size)
    {
        array = new int[size];
        ci = 0;
        capacity = size;
    }

    void push(int data)
    {
        if (ci == capacity)
        {
            cout << "Stack is full\n";
            return;
        }
        array[ci] = data;
        ci++;
    }
    bool isEmpty()
    {
        return ci == 0;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack empty";
            return -1;
        }
        ci--;
        return array[ci];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack empty !!";
            return -1;
        }
        int x = array[ci - 1];
        return x;
    }
};

int main()
{
    Stack s1(5);
    //checking if the functions are working properly or not
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout << s1.top() << endl; //displays topmost element i.e. 5
    cout << s1.pop() << endl; //to delete top ele 5 but actually it just moves ci one step back
    cout << s1.pop() << endl; //4
    cout << s1.pop() << endl; //4 the value of ci=2
    cout << s1.isEmpty() << endl;
    cout << s1.top() << endl; //2
}