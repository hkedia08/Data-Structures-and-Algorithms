// https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/

// https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

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
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node *root = new Node();
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // for every string start from root node
        Node *node = root;
        for (int j = i; j < s.size(); j++)
        {
            if (!node->containsKey(s[j]))
            {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    // dont forget  to count empty string
    return cnt + 1;
}