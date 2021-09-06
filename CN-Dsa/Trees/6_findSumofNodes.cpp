#define TreeNode Treenode
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class Treenode
{
public:
    T data;
    vector<Treenode *> children;
    Treenode(T data)
    {
        this->data = data;
    }
    ~Treenode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
Treenode<int> *takeinput_levelw()
{
    int rootdata;
    cout << "Enter root data  ";
    cin >> rootdata;
    Treenode<int> *root = new Treenode<int>(rootdata);

    queue<Treenode<int> *> remainode;
    remainode.push(root);
    while (remainode.size() != 0)
    {
        Treenode<int> *front = remainode.front();
        remainode.pop();

        int n;
        cout << "Number of children of the " << front->data << " ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childdata;
            cout << "Enter " << i << "th child of" << front->data << " ";
            cin >> childdata;
            Treenode<int> *child = new Treenode<int>(childdata); //dynamic allocation because we want this memory to survive
            front->children.push_back(child);
            remainode.push(child);
        }
    }
    return root;
}
int sumOfNodes(Treenode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum;
}

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *child = maxDataNode(root->children[i]);
        if (child->data > max->data)
            max = child;
    }
    return max;
}

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
void printAtK(Treenode<int> *root, int K)
{
    if (!root)
    {
        return;
    }
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

int main()
{
    Treenode<int> *root = takeinput_levelw();
    //cout << endl << sumOfNodes(root) << endl;
    cout << maxDataNode(root);
    //printAtK(root, 2);
    cout << getLeafNodeCount(root);
    delete root;
    return 0;
}