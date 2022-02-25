// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
class Node
{
public:
    Node *links[2];
    Node()
    {
        links[0] = NULL;
        links[1] = NULL;
    }
    bool containsKey(int val)
    {
        return (links[val] != NULL);
    }
    Node *get(int val)
    {
        return links[val];
    }
    void put(int val, Node *node)
    {
        links[val] = node;
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
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ;
        for (int i = 0; i < queries.size(); i++)
        {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oQ.begin(), oQ.end());
        int n = nums.size();
        int q = queries.size();
        Trie trie;
        int in = 0;
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++)
        {
            int maxi = -1;
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int indx = oQ[i].second.second;
            while (in < n && nums[in] <= ai)
            {
                trie.insert(nums[in]);
                in++;
            }
            // edge case when trie doesnot contain anything then we had to put -1
            // else we had to find maximum
            if (in != 0)
            {
                maxi = max(maxi, trie.getMax(xi));
                ans[indx] = maxi;
            }
            else
            {
                ans[indx] = -1;
            }
        }
        return ans;
    }
};