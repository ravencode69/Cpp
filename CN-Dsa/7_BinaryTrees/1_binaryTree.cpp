#include <iostream>
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
void printTree(BinaryTree<int> *root)
{
    if (!root) //in binary tree we'll be writing our base case unlike generic trees.
    {
        return;
    }
    cout << root->data;
    if (root->left)
    {
        cout << " L" << root->left->data;
    }
    if (root->right)
    {
        cout << " R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
BinaryTree<int> *Takeinput()
{
    int rd;
    cout << "Enter data ";
    cin >> rd;
    if (rd == -1)
    {
        return NULL;
    }

    BinaryTree<int> *root = new BinaryTree<int>(rd);
    BinaryTree<int> *Leftchild = Takeinput();
    BinaryTree<int> *Rightchild = Takeinput();

    root->left = Leftchild;
    root->right = Rightchild;

    return root;
}

int main()
{
    // BinaryTree<int> *root = new BinaryTree<int>(1);
    // BinaryTree<int> *node1 = new BinaryTree<int>(2);
    // BinaryTree<int> *node2 = new BinaryTree<int>(3);
    // root->left = node1;
    // root->right = node2;
    BinaryTree<int> *root = Takeinput();
    printTree(root);

    delete root;
}