#include <iostream>
#include <queue>
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
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
using namespace std;
#include <vector>
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
/*Given a BST and an integer k. Find and return the path from the node with data k
 and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
 SAMPLE TREE : 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1*/

vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (!root)
        return NULL;

    if (data == root->data)
    {
        vector<int> *v = new vector<int>();
        v->push_back(root->data);
        return v;
    }

    vector<int> *leftop = getPath(root->left, data);
    if (leftop)
    {
        leftop->push_back(root->data);
        return leftop;
    }
    vector<int> *rytop = getPath(root->right, data);
    if (rytop)
    {
        rytop->push_back(root->data);
        return rytop;
    }
    else
        return NULL;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL)
    {
        for (int i = 0; i < output->size(); i++)
        {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}