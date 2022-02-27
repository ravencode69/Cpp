#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Linkedlist
{
    Node *first;

public:
    Linkedlist() { first = NULL; }
    Linkedlist(int a[], int n);
    ~Linkedlist();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};
int Linkedlist::Length()
{
    struct Node *p = first;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

Linkedlist::Linkedlist(int a[], int n)
{
    Node *t, *last;

    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
Linkedlist::~Linkedlist()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
    p = nullptr;
}

void Linkedlist::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << "  ";
        p = p->next;
    }
}

void Linkedlist::Insert(int index, int x)
{

    Node *p = first, *t;

    if (index < 1 && index > Length())
        return;
    else if (index == 1)
    {
        t = new Node;
        t->data = x;
        t->next = NULL;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Linkedlist::Delete(int index)
{

    Node *p = first, *q;
    int x;

    if (index < 1 && index > Length())
    {
        return 0;
    }

    if (index == 1)
    {
        first = first->next;
        x = first->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {1, 3, 4, 5, 6, 9};
    Linkedlist l(A, 6);
    // l.Display();
    l.Delete(3);
    l.Display();
    return 0;
}
