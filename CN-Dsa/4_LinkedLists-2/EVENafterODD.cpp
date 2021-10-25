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
        this->next = NULL;
    }
};
Node *evenAfterOdd(Node *head)
{
    Node *oddh = NULL, *oddt = NULL, *event = NULL, *evenh = NULL;

    while (head)
    {
        if (head->data % 2 == 0)
        {
            if (evenh == NULL)
            {
                evenh = event = head;
                head = head->next;
                event->next = NULL;
            }
            else
            {
                event->next = head;
                head = head->next;
                event = event->next;
            }
        }
        else
        {
            if (oddh == NULL)
            {
                oddh = oddt = head;
                head = head->next;
                oddt->next = NULL;
            }
            else
            {
                oddt->next = head;
                head = head->next;
                oddt = oddt->next;
            }
        }
    }
    if (oddh == NULL)
    {
        return evenh;
    }
    else
    {
        if (evenh)
        {
            event->next = NULL;
            oddt->next = NULL;
            oddt->next = evenh;
            return oddh;
        }
        else
        {
            return oddh;
        }
    }
}

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
        head = evenAfterOdd(head);
        print(head);
    }
    return 0;
}