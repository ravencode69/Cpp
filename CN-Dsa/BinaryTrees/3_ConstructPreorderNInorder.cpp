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

/*-------Construction of tree---------------*/
BinaryTreeNode<int> *BinaryTreehelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
        return NULL;
    int rootdata = pre[preS];
    int ri = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootdata)
        {
            ri = i;
            break;
        }
    }
    int lpreS = preS + 1;
    int linS = inS;
    int linE = ri - 1;
    int lpreE = lpreS + linE - linS;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rinS = ri + 1;
    int rinE = inE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    root->left = BinaryTreehelper(in, pre, linS, linE, lpreS, lpreE);
    root->right = BinaryTreehelper(in, pre, rinS, rinE, rpreS, rpreE);

    return root;
}
BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return BinaryTreehelper(inorder, preorder, 0, inLength - 1, 0, preLength - 1);
}
/*-------Construction of tree---------------*/

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}
int main()
{
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}