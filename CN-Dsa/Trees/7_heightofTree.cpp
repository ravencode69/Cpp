
int getHeight(TreeNode<int> *root)
{
    int ctr = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallctr = getHeight(root->children[i]);
        if (ctr < smallctr)
            ctr = smallctr;
    }
    return ctr + 1;
}