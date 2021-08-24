#include <iostream>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *appendLastNToFirst(Node *head, int n)
{
    if (!head || n <= 0)
        return head;
    Node *c = head;
    Node *p = head, *q = head;
    int ctr = 0;
    while (c)
    {
        c = c->next; //length of ll
        ctr++;
    }
    for (int i = 0; i < ctr - n; i++) //**
    {
        p = p->next;
    }
    for (int i = 0; i < n; i++)
    {
        q = q->next;
    }
    q->next = head;
    head = p->next;
    p->next = NULL;

    return head;
}

Node *
takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}