#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
    Node *head, *tail;
    int size;

public:
    Queue()
    {
        tail = head = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            tail = head = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        Node *t = head;
        int x = t->data;
        delete t;
        head = head->next;
        size--;
        return x;
    }

    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Queue q;

    int t;
    cin >> t;

    while (t--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            q.enqueue(input);
            break;
        case 2:
            cout << q.dequeue() << "\n";
            break;
        case 3:
            cout << q.front() << "\n";
            break;
        case 4:
            cout << q.getSize() << "\n";
            break;
        default:
            cout << ((q.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}