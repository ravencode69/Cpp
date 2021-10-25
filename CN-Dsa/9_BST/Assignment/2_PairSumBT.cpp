#include <bits/stdc++.h>

void convert(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
        return;

    v.push_back(root->data);

    convert(root->left, v);
    convert(root->right, v);
}

void pairSum(BinaryTreeNode<int> *root, int sum)
{

    vector<int> v;
    convert(root, v);

    sort(v.begin(), v.end());
    int i = 0, j = v.size() - 1;

    while (i < j)
    {
        int t = v[i] + v[j];

        if (t == sum)
        {
            cout << v[i] << " " << v[j] << endl;
            i++;
            j--;
        }
        else if (t > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}