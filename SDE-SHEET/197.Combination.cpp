// https://leetcode.com/problems/combinations/

class Solution
{
public:
    void help(int idx, vector<int> &ans, vector<vector<int>> &res, int k, int n)
    {
        if (ans.size() == k)
        {
            res.push_back(ans);
            return;
        }
        for (int i = idx; i <= n; i++)
        {
            ans.push_back(i);
            help(i + 1, ans, res, k, n);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> ans;
        help(1, ans, res, k, n);
        return res;
    }
};