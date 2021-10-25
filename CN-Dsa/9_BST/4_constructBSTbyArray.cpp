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

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}
/*---------------------------------[ Code: Construct BST from a Sorted Array ]--------------------------------*/

BinaryTreeNode<int> *helper(int *arr, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }

    int mid = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);

    root->left = helper(arr, si, mid - 1);
    root->right = helper(arr, mid + 1, ei);

    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{

    return helper(input, 0, n - 1);
}

/*---------------------------------[ Code: Construct BST from a Sorted Array  [END]  ]--------------------------------*/
int main()
{
    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    BinaryTreeNode<int> *root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}