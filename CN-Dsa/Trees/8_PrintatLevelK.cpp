void printAtK(Treenode<int> *root, int K)
{
    if (K == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtK(root->children[i], K - 1);
    }
}