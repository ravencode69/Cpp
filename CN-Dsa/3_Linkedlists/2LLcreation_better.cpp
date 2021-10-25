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
Node *create_better()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL; //maintain a tail as well
    while (data != -1)
    {
        Node *newnode = new Node(data); //O(1) complexity
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode; //updating the tail.
            tail = newnode;
            //OR
            //tail=tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    Node *head = create_better();
    print(head);
}
