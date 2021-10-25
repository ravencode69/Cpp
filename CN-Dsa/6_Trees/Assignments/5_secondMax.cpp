#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
/*------------SECOND MAX CODE-------------------------------------------------------------------------------*/

class Pair
{
public:
    TreeNode<int> *max;
    TreeNode<int> *sec;
    Pair(TreeNode<int> *max, TreeNode<int> *sec)
    {
        this->max = max;
        this->sec = sec;
    }
};
Pair getLargestNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair r(NULL, NULL);
        return r;
    }
    Pair p(root, NULL);

    for (int i = 0; i < root->children.size(); i++)
    {
        Pair sp = getLargestNode(root->children[i]);
        TreeNode<int> *temp;
        if (sp.max->data > p.max->data)
        {
            if (sp.sec == NULL)
            {
                p.sec = p.max;
                p.max = sp.max;
            }
            else
            {
                if (sp.sec->data > p.max->data)
                {
                    p.sec = sp.sec;
                    p.max = sp.max;
                }
                else
                {
                    p.sec = p.max;
                    p.max = sp.max;
                }
            }
        }
        else
        {
            if (p.max->data != sp.max->data && (p.sec == NULL || sp.max->data > p.sec->data))
                p.sec = sp.max;
        }
    }
    return p;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    if (!root)
        return NULL;
    Pair ans = getLargestNode(root);
    return ans.sec;
}
/*------------SECOND MAX CODE-------------------------------------------------------------------------------*/

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}
