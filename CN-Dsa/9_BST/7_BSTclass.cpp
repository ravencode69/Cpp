#include <iostream>
#include <queue>
using namespace std; // namespace std;

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

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root == NULL;
    }

    /*----------------- Public Functions of BST -----------------*/
private:
    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *node)
    {

        if (node == NULL)
        {
            return NULL;
        }
        if (data > node->data)
        {
            node->right = remove(data, node->right);
            return node;
        }
        else if (data < node->data)
        {
            node->left = remove(data, node->left);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else
            {

                BinaryTreeNode<int> *minEle = node->right;
                while (minEle->left != NULL)
                {
                    minEle = minEle->left;
                }
                int rightmin = minEle->data;
                node->data = rightmin;
                node->right = remove(rightmin, node->right);
                return node;
            }
        }
    }

    void printTree(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL && root->right != NULL)
        {
            cout << "L:" << root->left->data << ",R:" << root->right->data;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

public:
    void remove(int data)
    {
        root = remove(data, root);
    }

    void print()
    {
        printTree(root);
    }

private:
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *Newnode = new BinaryTreeNode<int>(data);
            return Newnode;
        }
        else if (data > node->data)
        {
            node->right = insert(data, node->right); //agar node NULL hua toh naya root aaegya toh isliye tab attach v toh karna hoga
        }                                            //thats why
        else
        {
            node->left = insert(data, node->left);
        }
    }

public:
    void insert(int data)
    {
        root = insert(data, root);
    }

private:
    bool search(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return false;

        if (node->data == data)
            return true;

        else if (data < node->data)
            return search(data, node->left);
        else
            return search(data, node->right);
    }

public:
    bool search(int data)
    {
        return search(data, root);
    }
};

int main()
{
    BST b;
    b.insert(4);
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(6);
    b.insert(7);
    b.insert(5);
    b.print();
}