#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    bool
    search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL)
            return false;

        return search(root->children[index], word.substr(1));
    }

    void pautoComplete(TrieNode *root, string pattern)
    {

        if (root->isTerminal)
            cout << pattern << endl;

        for (int i = 0; i < 26; i++)
        {
            char w = i + 'a';
            if (root->children[i] != NULL)
                pautoComplete(root->children[i], w + pattern);
        }
        return;
    }

    void autoComplete(vector<string> input, string pattern)
    {
        // Write your code here

        // build a trie
        for (int i = 0; i < input.size(); i++)
        {
            insertWord(input[i]);
        }
        if (search(root, pattern) == false)
            return;

        string s = pattern;

        while (pattern.length() != 0)
        {
            root = root->children[pattern[0] - 'a'];
            pattern = pattern.substr(1);
        }
        pautoComplete(root, s);
    }
};