pair<Node<int> *, Node<int> *> helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node<int> *, Node<int> *> p;
        p.first = NULL;  //head
        p.second = NULL; //tail
        return p;
    }

    Node<int> *node = new Node<int>(root->data);

    pair<Node<int> *, Node<int> *> leftans = helper(root->left);
    pair<Node<int> *, Node<int> *> rytans = helper(root->right);

    pair<Node<int> *, Node<int> *> ans;

    if (!leftans.first && !rytans.first)
    {
        ans.first = ans.second = node;
    }
    else if (!leftans.first && rytans.first)
    {
        ans.first = node;
        ans.first->next = rytans.first;
        ans.second = rytans.second;
    }
    else if (leftans.first && !rytans.first)
    {
        ans.first = leftans.first;
        leftans.second->next = node;
        leftans.second = leftans.second->next;
        ans.second = leftans.second;
    }
    else
    {
        ans.first = leftans.first;
        leftans.second->next = node;
        node->next = rytans.first;
        ans.second = rytans.second;
    }

    return ans;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{

    return helper(root).first;
}