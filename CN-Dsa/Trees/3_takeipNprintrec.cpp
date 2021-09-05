#include <iostream>
#include <vector>
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
};
Treenode<int> *takeinput()
{
    int rootData, n;
    cout << "rootdata";
    cin >> rootData;
    Treenode<int> *root = new Treenode<int>(rootData);
    cout << "no. of children";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Treenode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

void printtree(Treenode<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children[i]);
    }
}

int main()
{
    Treenode<int> *root = takeinput();
    /*
    Treenode<int> *root = new Treenode<int>(100);
    Treenode<int> *node1 = new Treenode<int>(200);
    Treenode<int> *node2 = new Treenode<int>(300);
    root->children.push_back(node1);
    root->children.push_back(node2);*/
    printtree(root);
    return 0;
}