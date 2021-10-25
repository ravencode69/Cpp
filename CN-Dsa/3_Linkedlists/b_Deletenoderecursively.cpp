// Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively.

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
Node *deleteNodeRec(Node *head, int pos)
{
    if (!head || pos < 0)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *d = head;
        head = head->next;
        delete d;
        return head;
    }
    Node *smallh = deleteNodeRec(head->next, pos - 1);
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
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = create();
        int pos;
        cin >> pos;
        head = deleteNodeRec(head, pos);
        print(head);
    }

    return 0;
}