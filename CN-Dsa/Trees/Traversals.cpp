
void printPostOrder(TreeNode<int> *root)
{
    if (!root)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}

void printPreOrder(TreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
}
