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

/*-------------search in BST ----------------------------------------------------*/

bool searchInBST(BinaryTreeNode<int> *root, int k)
{

    if (!root)
        return false;

    else
    {
        if (k == root->data)
            return true;
        else
        {
            if (k > root->data)
                return searchInBST(root->right, k);
            else
                return searchInBST(root->left, k);
        }
    }
}

/*-------------[ PRINT ELEMENTS IN RANGE ] ----------------------------------------------------*/
void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{

    if (NULL == root)
        return;

    if (k1 < root->data)
        elementsInRangeK1K2(root->left, k1, k2);

    if (k1 <= root->data && k2 >= root->data)
        cout << root->data << " ";

    if (k2 > root->data)
        elementsInRangeK1K2(root->right, k1, k2);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true" : "false") << endl;
    elementsInRangeK1K2(root, 4, 9);

    delete root;
} //4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1