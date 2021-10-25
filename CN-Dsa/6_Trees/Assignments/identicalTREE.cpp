bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{

    if (root1->data != root2->data)
        return false;

    if (root1->children.size() != root2->children.size())
        return false;

    bool ans = true;

    for (int i = 0; i < root1->children.size(); i++)
    {
        bool smallans = areIdentical(root1->children[i], root2->children[i]);

        if (smallans == false)
        {
            ans = smallans;
            return ans;
        }
    }
    return ans;
}