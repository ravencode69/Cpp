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
    Node *p = head, *a = head, *b = head;
    int l = 0;
    for (; p;)
    {
        p = p->next;
        l++;
    }
    for (int i = 1; i < l - n; i++)
    {
        a = a->next;
    }
    for (int i = 1; i < l; i++)
    {
        b = b->next;
    }
    b->next = head;
    head = a->next;
    a->next = NULL;
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