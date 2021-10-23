class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isterminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isterminal = false;
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode *root, string word)
    {

        // Base Case
        if (word.size() == 0)
        {
            root->isterminal = true;
            return;
        }

        // Small calc
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child; // connect
        }

        // recursive call
        insertWord(child, word.substr(1));
    }
    // for user
    void insertword(string word)
    {
        insertWord(root, word);
    }

    bool search(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isterminal;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL)
            return false;

        return search(root->children[index], word.substr(1));
    }
    bool search(string word)
    {
        return search(root, word);
    }
    void removeWord(string word, TrieNode *root)
    { // Base Case
        if (word.size() == 0)
        {
            root->isterminal = false;
            return;
        }

        // small calc.
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // word not found
            return;
        }
        removeWord(word.substr(1), child);

        // remove child node if it is useless
        if (child->isterminal = false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void removeWord(string word)
    {
        removeWord(word, root);
    }
};
