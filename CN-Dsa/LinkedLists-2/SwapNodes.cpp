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
        this->next = nullptr;
    }
};

Node *swapNodes(Node *head, int i, int j)
{
    if (i == j)
        return head; //NO changes

    Node *prevX, *prevY, *x, *y;

    prevX = prevY = NULL;
    x = y = head;

    for (int v = 0; v < i && x; v++)
    {
        prevX = x;
        x = x->next;
    }

    for (int v = 0; v < j && y; v++)
    {
        prevY = y;
        y = y->next;
    }

    Node *temp = y->next;

    if (x->next != y && y->next != x)
    {

        y->next = x->next;
        x->next = temp;

        if (prevX == NULL)
        {
            head = y;
            prevY->next = x;
        }

        else if (prevY == NULL)
        {
            head = x;
            prevX->next = y;
        }

        else if (prevX && prevY)
        {
            prevY->next = x;
            prevX->next = y;
        }
    }

    //Gimme a break

    else
    {
        if (x->next == y)
        {

            prevX->next = y;
            y->next = x;
            x->next = temp;
        }
        else if (y->next == x)
        {
            Node *temp2 = x->next;
            prevY->next = x;
            x->next = y;
            y->next = temp2;
        }
    }

    return head;
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
        int i, j;
        Node *head = takeinput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}
