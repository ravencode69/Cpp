#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void display();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack is full";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int Stack::pop()
{
    Node *p;
    int x = -1;
    if (top == NULL)
        cout << "Stack empty";
    else
    {
        p = top;
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;
}

void Stack::display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}
int main()
{

    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    cout << stk.pop();

    // stk.display();
    return 0;
}