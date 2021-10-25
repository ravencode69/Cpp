#include <iostream>
#include <queue>
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
    int rootdata;
    cout << "rootdata ";
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int> *> remain;
    remain.push(root);
    while (remain.size() != 0)
    {

        BinaryTreeNode<int> *front = remain.front();
        remain.pop();
        int leftchild;
        cout << "Left child of " << front->data << " ";
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftchild);
            front->left = child;
            remain.push(child);
        }

        int rightchild;
        cout << "Right child of " << front->data << " ";
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightchild);
            front->right = child;
            remain.push(child);
        }
    }
    return root;
}
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
int height(BinaryTreeNode<int> *root)
{

    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int Diameter(BinaryTreeNode<int> *root)
{
    //O(n*h)
    if (!root)
        return 0;

    int d1 = height(root->left) + height(root->right);
    int d2 = height(root->right);
    int d3 = height(root->left);
    return max(d1, (d2, d3));
}
pair<int, int> giveHeightDia(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        pair<int, int> p;
        p.first = 0;  //height
        p.second = 0; //diameter
        return p;
    }
    pair<int, int> leftAns = giveHeightDia(root->left);
    pair<int, int> rightAns = giveHeightDia(root->right);

    int lh = leftAns.first; //O(n)
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    pair<int, int> j = giveHeightDia(root);
    cout << j.first << " is h" << j.second << " diameter";
    delete root;
    return 0;
}
