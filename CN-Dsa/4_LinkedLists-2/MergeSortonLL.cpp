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
Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *mid = middle(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    Node *sl1 = mergeSort(head);
    Node *sl2 = mergeSort(head2);
    Node *Newhead = mergeTwoSortedLinkedLists(sl1, sl2);
    return Newhead;
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
        head = mergeSort(head);
        print(head);
    }

    return 0;
}
