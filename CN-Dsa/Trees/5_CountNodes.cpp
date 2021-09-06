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

int countNode(Treenode<int> *root)
{
    int n = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        n = n + countNode(root->children[i]);
    }
    return n;
}

int main()
{
    Treenode<int> *root = takeinput_levelw();
    cout << countNode(root);
    return 0;
}
