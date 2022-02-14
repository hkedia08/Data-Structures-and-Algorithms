// https://leetcode.com/problems/combination-sum-iii/

class Solution
{
public:
    void help(int idx, vector<int> &ans, vector<vector<int>> &res, int k, int n, int sum)
    {
        if (ans.size() == k)
        {
            if (sum == n)
                res.push_back(ans);
            return;
        }
        for (int i = idx; i <= 9; i++)
        {
            sum += i;
            ans.push_back(i);
            help(i + 1, ans, res, k, n, sum);
            ans.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> ans;
        help(1, ans, res, k, n, 0);
        return res;
    }
};