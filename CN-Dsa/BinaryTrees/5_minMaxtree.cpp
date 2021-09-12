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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

#include <algorithm>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{

    if (root->left == NULL && root->right == NULL)
    {
        pair<int, int> ans;
        ans.first = ans.second = root->data;
        return ans;
    }

    pair<int, int> ans;
    ans.first = ans.second = root->data;
    pair<int, int> leftside;
    pair<int, int> rightside;

    if (root->left)
    {
        leftside = getMinAndMax(root->left);
        ans.first = min(leftside.first, ans.first);
        ans.second = max(leftside.second, ans.second);
    }

    if (root->right)
    {
        rightside = getMinAndMax(root->right);
        ans.first = min(rightside.first, ans.first);
        ans.second = max(rightside.second, ans.second);
    }

    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}