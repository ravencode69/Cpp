#include <iostream> // a really simple implimentation of stack through linked lists
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

class Stack
{
    Node *head;
    int s;

public:
    Stack()
    {
        head = NULL;
        s = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return s;
    }

    bool isEmpty()
    {
        return s == 0;
    }

    void push(int element)
    {
        if (head == NULL)
        {
            head = new Node(element);
            s++;
        }
        else
        {
            Node *temp = new Node(element);
            temp->next = head;
            head = temp;
            s++;
        }
    }

    int pop()
    {
        if (s == 0)
        {
            return -1;
        }
        Node *t = head;
        head = head->next;
        s--;
        int x = t->data;
        delete t;
        return x;
    }

    int top()
    {
        if (s == 0)
        {
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Stack st;

    int q;
    cin >> q;

    while (q--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            st.push(input);
            break;
        case 2:
            cout << st.pop() << "\n";
            break;
        case 3:
            cout << st.top() << "\n";
            break;
        case 4:
            cout << st.getSize() << "\n";
            break;
        default:
            cout << ((st.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}