#include <iostream>
#include <queue>
#include <stack>
template <typename T>
class Node //for Levelwise LL problem
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
/*----------------1. Sum Of Nodes------------------------------------------*/
int getSum(BinaryTreeNode<int> *root)
{

    if (!root)
        return 0;

    int sum = 0;
    sum = root->data;
    if (root->left)
    {
        int ls = getSum(root->left);
        sum += ls;
    }
    if (root->right)
    {
        int rs = getSum(root->right);
        sum += rs;
    }

    return sum;
}
/*----------------2. Check Balanced----------------------------------------*/
int hei(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    int h = 1 + hei(root->left) + hei(root->right);

    return h;
}
bool isBalanced(BinaryTreeNode<int> *root)
{

    if (!root)
        return true;
    int lh = hei(root->left);
    int rh = hei(root->right);

    if (abs(lh - rh) > 1)
        return false;
    return true;
}
/*----------------3. Level order traversal--------------------------------*/
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    queue<BinaryTreeNode<int> *> remain;
    remain.push(root);
    remain.push(NULL);
    while (!remain.empty())
    {
        BinaryTreeNode<int> *front = remain.front();
        remain.pop();

        if (front == NULL)
        {
            if (remain.size() == 0)
                break;
            else
            {
                cout << endl;
                remain.push(NULL);
            }
        }

        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                remain.push(front->left);
            }
            if (front->right)
            {
                remain.push(front->right);
            }
        }
    }
}
/*----------------4. Remove leaf-----------*/
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{

    if (!root || root->left == NULL && root->right == NULL)
    {
        if (root)
        {
            delete root;
        }
        return NULL;
    }

    BinaryTreeNode<int> *ls = removeLeafNodes(root->left);
    BinaryTreeNode<int> *rs = removeLeafNodes(root->right);

    root->left = ls;
    root->right = rs;

    return root;
}
/*----------------5. Level wise linkedlist--------------------------------*/
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> op;
    if (!root)
    {
        op.push_back(NULL);

        return op;
    }

    queue<BinaryTreeNode<int> *> remain;
    remain.push(root);
    remain.push(NULL);

    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while (!remain.empty())
    {
        BinaryTreeNode<int> *front = remain.front();
        remain.pop();

        if (front == NULL)
        {
            tail->next = NULL;
            if (remain.empty())
                break;

            remain.push(NULL);
            head = tail = NULL;
        }

        else
        {
            Node<int> *node = new Node<int>(front->data);

            if (head == NULL)
            {
                head = tail = node;
                op.push_back(head);
            }
            else
            {
                tail->next = node;
                tail = tail->next;
            }
            if (front->left)
                remain.push(front->left);
            if (front->right)
                remain.push(front->right);
        }
    }
    return op;
}
/*-------------------6. ZIG ZAC TREE--------------------------------------*/
void zigZagOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    stack<BinaryTreeNode<int> *> s1, s2;
    s1.push(root);
    while (!s1.empty() && !s2.empty())
    {
        if (!root)
            return;

        stack<BinaryTreeNode<int> *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            while (!s1.empty())
            {
                BinaryTreeNode<int> *cur = s1.top();
                s1.pop();
                cout << cur->data << " ";

                if (cur->left)
                    s2.push(cur->left);
                if (cur->right)
                    s2.push(cur->right);
            }
            cout << endl;

            while (!s2.empty())
            {
                BinaryTreeNode<int> *cur = s2.top();
                s2.pop();
                cout << cur->data << " ";

                if (cur->right)
                    s1.push(cur->right);
                if (cur->left)
                    s1.push(cur->left);
            }
            cout << endl;
        }
    }
}
/*------------------------7.Nodes without sibling-------------------------*/
void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{

    if (!root)
        return;

    if (!root->left && root->right)
        cout << root->right->data << " ";

    else if (root->left && !root->right)
        cout << root->left->data << " ";

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

/*___________-----------------------MAIN FUNC---------------------_________*/
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    zigZagOrder(root);
}