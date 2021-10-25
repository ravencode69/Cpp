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

Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *reverseLL(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    Node *front = head;
    Node *mid = middle(head);
    Node *backside = reverseLL(mid);
    while (front && backside)
    {
        if (front->data != backside->data)
            return false;
        front = front->next;
        backside = backside->next;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}