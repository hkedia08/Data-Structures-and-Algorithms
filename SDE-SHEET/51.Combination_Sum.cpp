// https://leetcode.com/problems/combination-sum/
// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#

class Solution
{
public:
    void help(int i, vector<int> &candidates, vector<vector<int>> &res, vector<int> &ans, int target)
    {
        if (target != 0 && i == candidates.size())
            return;
        if (target == 0 && i == candidates.size())
        {
            res.push_back(ans);
            return;
        }
        if (candidates[i] <= target)
        {
            ans.push_back(candidates[i]);
            help(i, candidates, res, ans, target - candidates[i]);
            ans.pop_back();
        }
        help(i + 1, candidates, res, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> ans;
        vector<vector<int>> res;
        help(0, candidates, res, ans, target);
        return res;
    }
};