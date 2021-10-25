// You have been given a linked list of integers.Your task is to write a function that inserts a node at a given position, 'pos'.
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
Node *Insertnode(Node *head, int pos, int data)
{
    if (!head || pos < 0) //is head is null or pos is less than zero exit
    {
        return head;
    }

    if (pos == 0)
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        head = newnode;
    }
    Node *smallh = Insertnode(head->next, pos - 1, data); //pos-1 whats 1 for us is 0 for recursion.
    head->next = smallh;
    return head;
}

Node *create()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
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
    int testcases;
    cin >> testcases;
    while (testcases)
    {
        Node *head = create();
        int pos, data;
        cin >> pos >> data;
        head = Insertnode(head, pos, data);
        print(head);
    }
}
