// https://leetcode.com/problems/subsets/
class Solution
{
public:
    void help(int idx, vector<int> &nums, vector<int> &ans, vector<vector<int>> &res, int n)
    {
        res.push_back(ans);
        for (int i = idx; i < n; i++)
        {
            ans.push_back(nums[i]);
            help(i + 1, nums, ans, res, n);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> ans;
        help(0, nums, ans, res, n);
        return res;
    }
};