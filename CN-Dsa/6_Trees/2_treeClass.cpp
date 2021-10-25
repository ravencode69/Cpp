#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Treenode
{
public:
    T data;
    vector<Treenode<T> *> children; //dynamic allocation
    Treenode(T data)
    {
        this->data = data;
    }
};
int main()
{
    Treenode<int> *root = new Treenode(1);
    Treenode<int> *node1 = new Treenode(2);
    Treenode<int> *node2 = new Treenode(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
}