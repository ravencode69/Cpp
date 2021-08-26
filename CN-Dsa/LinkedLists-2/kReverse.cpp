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
class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverse(Node *head)
{
    if (!head || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallerans = reverse(head->next);
    smallerans.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallerans.head;
    ans.tail = head;

    return ans;
}

Node *kReverse(Node *head, int n)
{
    if (head == NULL)
        return NULL;

    Node *h1 = head, *t1 = head;
    int count = 1;

    // counting till n nodes
    while (count < n && t1->next)
    {
        t1 = t1->next;
        count++;
    }
    //break this part from LL
    // and reverse it
    Node *h2 = t1->next;
    t1->next = NULL;

    Pair smallans = reverse(h1);
    // we have head and tail of reversed LL in small ans

    h2 = kReverse(h2, n);

    // connecting LL again

    smallans.tail->next = h2;

    return smallans.head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }

    return 0;
}