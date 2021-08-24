#include <iostream>
using namespace std;
/*----------------------------------method-1--------------------------------------------------*/
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

Node *create()
{
    int data;
    cin >> data;

    Node *head = NULL; //**

    while (data != -1)
    {
        Node *newnode = new Node(data); //**
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL) //Extra work has been done everytime we inset a new node node
            {                          //i.e. we'll have to do n-1 comparision to insert n'th node
                temp = temp->next;
            }
            temp->next = newnode;
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
    Node *head = create();
    print(head);
}