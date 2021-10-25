int getLeafNodeCount(TreeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        return 1;
    }
    int ctr = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ctr = ctr + getLeafNodeCount(root->children[i]);
    }
    return ctr;
}