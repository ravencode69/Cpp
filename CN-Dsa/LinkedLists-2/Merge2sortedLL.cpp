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
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 && head2)
    {
        Node *Thead = NULL, *Ttail = NULL;
        if (head1->data < head2->data)
        {
            Thead = Ttail = head1;
            head1 = head1->next;
            Ttail->next = NULL;
        }
        else
        {
            Thead = Ttail = head2;
            head2 = head2->next;
            Ttail->next = NULL;
        }

        while (head1 && head2)
        {
            if (head1->data < head2->data)
            {
                Ttail->next = head1;
                Ttail = head1;
                head1 = head1->next;
                Ttail->next = NULL;
            }

            else
            {
                Ttail->next = head2;
                Ttail = head2;
                head2 = head2->next;
                Ttail->next = NULL;
            }
        }
        if (head1)
        {
            Ttail->next = head1;
        }
        else
        {
            Ttail->next = head2;
        }

        return Thead;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        print(head3);
    }
    return 0;
}