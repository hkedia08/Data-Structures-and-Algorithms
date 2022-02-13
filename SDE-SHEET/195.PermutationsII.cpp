// https://leetcode.com/problems/permutations-ii/

class Solution
{
public:
    void help(vector<int> &nums, vector<int> &ans, set<vector<int>> &res, int frequency[])
    {
        if (ans.size() == nums.size())
        {
            res.insert(ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (frequency[i] == 0)
            {
                frequency[i] = 1;
                ans.push_back(nums[i]);
                help(nums, ans, res, frequency);
                frequency[i] = 0;
                ans.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> res;
        vector<int> ans;
        int n = nums.size();
        int frequency[n];
        for (int i = 0; i < n; i++)
            frequency[i] = 0;
        help(nums, ans, res, frequency);
        vector<vector<int>> res1;
        for (auto it : res)
        {
            res1.push_back(it);
        }
        return res1;
    }
};