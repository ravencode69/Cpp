TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{

    if (root == NULL)
        return NULL;
    TreeNode<int> *ans = NULL;

    if (root->data > x)
        ans = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *sans = getNextLargerElement(root->children[i], x);

        if (sans == NULL)
            continue;
        else
        {
            if (ans == NULL)
                ans = sans;
            else if (sans->data < ans->data)
                ans = sans;
        }
    }
    return ans;
}