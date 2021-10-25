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
Node *takeinput()
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

Node *skipMdeleteN(Node *head, int m, int n)
{
    if (m == 0) //edge case
    {
        return NULL;
    }
    if (!head || n == 0) //base case
    {
        return head;
    }
    Node *p = head;

    while (p)
    {
        for (int i = 0; i < m - 1 && p; i++)
        {
            p = p->next;
        }

        Node *q = NULL;
        if (p)
            q = p->next;

        for (int i = 0; i < n && q; i++)
        {
            Node *temp = q;
            q = q->next;
            delete temp;
        }
        if (p)
        {
            p->next = q;
            p = q;
        }
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
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}