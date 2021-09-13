#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
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
/*--------------Approach 1 :- ================================[  T(n)=(n*h) ]==========================>*/

int minimum(BinaryTreeNode<int> *root)
{
    if (!root)
        return INT_MAX;

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root)
{
    if (!root)
        return INT_MIN;

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) //T(n)=(n*h)
{

    if (!root)
        return true;

    int minofright = minimum(root->right);
    int maxofleft = maximum(root->left);

    if (root->data > maxofleft && root->data < minofright && isBST(root->left) && isBST(root->right))
        return true;
    else
        return false;
}
/*--------------Approach 2 :- ====================================[ T(n) = (n)]======================>*/

pair<bool, pair<int, int>> Isbst2help(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<bool, pair<int, int>> p;
        p.first = true;
        p.second.first = INT_MAX;  //mini
        p.second.second = INT_MIN; //maxi
        return p;
    }

    pair<bool, pair<int, int>> leftop = Isbst2help(root->left);
    pair<bool, pair<int, int>> rightop = Isbst2help(root->right);

    int minimum = min(root->data, min(leftop.second.first, rightop.second.first));
    int maximum = max(root->data, max(leftop.second.second, rightop.second.second));

    bool finalbst = (root->data > leftop.second.second) && (root->data < rightop.second.first) && (leftop.first) && (rightop.first);

    pair<bool, pair<int, int>> output;
    output.first = finalbst;
    output.second.first = minimum;
    output.second.second = maximum;
    return output;
}
bool isBSTBetter(BinaryTreeNode<int> *root)
{
    bool ans = Isbst2help(root).first;
    return ans;
}
//sample tree-    9 3 10 2 5 -1 -1 -1 -1 -1 6 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBST(root) ? "true" : "false");
    cout << (isBSTBetter(root) ? "true" : "false");
}