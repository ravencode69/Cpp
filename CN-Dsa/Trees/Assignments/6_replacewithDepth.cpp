void helper(TreeNode<int> *root, int depth)
{
    if (root)
    {
        root->data = depth;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        helper(root->children[i], depth + 1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root)
{

    helper(root, 0);
}