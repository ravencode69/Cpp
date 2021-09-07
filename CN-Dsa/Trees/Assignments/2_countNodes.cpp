

int getLargeNodeCount(TreeNode<int> *root, int x)
{
    int ctr = 0;
    if (root->data > x)
    {
        ctr++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ctr = ctr + getLargeNodeCount(root->children[i], x);
    }
    return ctr;
}