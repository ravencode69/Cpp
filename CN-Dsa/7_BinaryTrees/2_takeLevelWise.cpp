#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTree()
    {
        delete left;
        delete right;
    }
};
/*------------take input levelwise---------------*/
BinaryTree<int> *takeinput()
{
    int rootdata;
    cout << "rootdata ";
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;
    BinaryTree<int> *root = new BinaryTree<int>(rootdata);
    queue<BinaryTree<int> *> remain;
    remain.push(root);
    while (remain.size() != 0)
    {

        BinaryTree<int> *front = remain.front();
        remain.pop();
        int leftchild;
        cout << "Left child of " << front->data << " ";
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(leftchild);
            front->left = child;
            remain.push(child);
        }

        int rightchild;
        cout << "Right child of " << front->data << " ";
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(rightchild);
            front->right = child;
            remain.push(child);
        }
    }
    return root;
}
/*-----------print levelwise---------------*/
void printLevelWise(BinaryTree<int> *root)
{
    if (!root)
        return;
    queue<BinaryTree<int> *> remain;
    remain.push(root);
    while (remain.size() != 0)
    {
        BinaryTree<int> *front = remain.front();
        remain.pop();
        cout << front->data << ":";
        if (front->left)
        {
            cout << "L:" << front->left->data << ",";
            remain.push(front->left);
        }
        else
            cout << "L:-1,";
        if (front->right)
        {
            cout << "R:" << front->right->data << endl;
            remain.push(front->right);
        }
        else
            cout << "R:-1" << endl;
    }
}

/*-------------------------------------------Counting the number of nodes-----------------------*/
int countNodes(BinaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    int count = 1 + countNodes(root->left) + countNodes(root->right);
    return count;
}
/*-------------------------------------------Counting the number of nodes-----------------------*/

/*----------------------Code : Find a node-------------------------*/
bool isNodePresent(BinaryTree<int> *root, int x)
{
    if (root == NULL) //base case
        return false;
    if (root->data == x)
        return true;
    bool ans = false;
    bool sa = isNodePresent(root->left, x);
    bool sa1 = isNodePresent(root->right, x);
    if (sa != ans && sa == true || sa1 != ans && sa1 == true)
    {
        ans = true;
    }
    return true;
}
/*----------------------Code : Find a node-------------------------*/

/*----------------------Code : Height of Binary Tree-------------------------*/

int height(BinaryTree<int> *root)
{
    int h = 0;
    if (!root)
        return h;

    int lh = height(root->left);
    int rh = height(root->right);
    if (lh > rh)
        return lh + 1;
    else
        rh + 1;
}
/*----------------------Code : Height of Binary Tree-------------------------*/

/*----------------------Code : MIRROR-------------------------*/
void mirror(BinaryTree<int> *root)
{
    if (!root)
        return;
    mirror(root->left);
    mirror(root->right);
    BinaryTree<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
/*----------------------Code : MIRROR-------------------------*/
void preOrder(BinaryTree<int> *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BinaryTree<int> *root)
{

    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTree<int> *root = takeinput();
    //printLevelWise(root);
    //mirror(root);
    // preOrder(root);
    //cout << countNodes(root);
    postOrder(root);
    delete root;
}