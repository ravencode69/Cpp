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

class BST
{
    BinaryTreeNode<int> *root; //by default point to garbage

public:
    BST()
    {
        root == NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (!node)
        {
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            return node;
        }
        else if (data > node->data)
        {
            node->left = insert(data, node->right); //agar node NULL hua toh naya root aaegya toh isliye tab attach v toh karna hoga
        }                                           //thats why
        else
        {
            node->right = insert(data, node->left);
        }
        return node;
    }

public:
    void insert(int data)
    {
        this->root = insert(data, this->root);
    }

private:
    BinaryTreeNode<int> *delData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
    }

public:
    void delData(int data)
    {
        this->root = delData(data, this->root);
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return false;

        if (node->data = data)
            return true;

        else if (data < node->data)
            return hasData(data, node->left);
        else
            return hasData(data, node->right);
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
};
