// https://leetcode.com/problems/combination-sum-ii/

class Solution
{
public:
    void help(int i, vector<int> &candidates, vector<vector<int>> &res, vector<int> &ans, int target)
    {
        if (target == 0)
        {
            res.push_back(ans);
            return;
        }
        if (i >= candidates.size() || target - candidates[i] < 0)
            return;
        auto it = candidates[i];
        ans.push_back(candidates[i]);
        help(i + 1, candidates, res, ans, target - candidates[i]);
        ans.pop_back();
        while (i < candidates.size() && candidates[i] == it)
            i++;
        help(i, candidates, res, ans, target);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> ans;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        help(0, candidates, res, ans, target);
        return res;
    }
};

// another approach striver video

class Solution
{
public:
    void help(int i, vector<int> &candidates, vector<vector<int>> &res, vector<int> &ans, int target)
    {
        if (target == 0)
        {
            res.push_back(ans);
            return;
        }
        for (int idx = i; idx < candidates.size(); idx++)
        {
            if (idx > i && candidates[idx - 1] == candidates[idx])
                continue;
            if (candidates[idx] > target)
                break;
            ans.push_back(candidates[idx]);
            help(idx + 1, candidates, res, ans, target - candidates[idx]);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> ans;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        help(0, candidates, res, ans, target);
        return res;
    }
};