// https://leetcode.com/problems/longest-word-with-all-prefixes/
// https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

class Node
{
    Node *links[26];
    bool flag = false;

public:
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool getEnd()
    {
        return flag;
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
        }
        node->setEnd();
    }

    bool checkIfAllPrefixExists(string word)
    {
        Node *node = root;
        bool flag = true;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                flag = flag & node->getEnd();
            }
            else
            {
                return false;
            }
        }
        return flag;
    }
};
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        string longest = "";
        Trie *obj = new Trie();
        for (auto it : words)
        {
            obj->insert(it);
        }
        for (auto it : words)
        {
            if (obj->checkIfAllPrefixExists(it))
            {
                if (it.size() > longest.size())
                    longest = it;
                else if (it.size() == longest.size() && it < longest)
                    longest = it;
            }
        }
        return longest;
    }
};