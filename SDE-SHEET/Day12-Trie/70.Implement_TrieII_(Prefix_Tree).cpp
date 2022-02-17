// https://leetcode.com/problems/implement-trie-ii-prefix-tree/
// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?leftPanelTab=0

class Node
{
    Node *link[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

public:
    bool containsKey(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return link[ch - 'a'];
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    void deletePrefix()
    {
        cntPrefix--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return 0;
            }
            node = node->get(prefix[i]);
        }
        return node->getPrefix();
    }

    void erase(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return;
            }
            node = node->get(word[i]);
            node->deletePrefix();
        }
        node->deleteEnd();
    }
};
