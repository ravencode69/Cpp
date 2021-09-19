
void insertDuplicateNode(BinaryTreeNode<int> *root)
{

    if (!root)
        return;
    BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(root->data);
    newnode->left = root->left;
    root->left = newnode;

    insertDuplicateNode(newnode->left);
    insertDuplicateNode(root->right);
}