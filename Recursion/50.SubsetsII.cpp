
// https://leetcode.com/problems/subsets-ii/

class Solution
{
public:
    void help(int idx, vector<int> &nums, vector<int> &ans, vector<vector<int>> &res, int n)
    {
        res.push_back(ans);
        for (int i = idx; i < n; i++)
        {
            // bcz i-1  se banane wale sare set consider kar lia wahi i se honge so ignore
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            ans.push_back(nums[i]);
            help(i + 1, nums, ans, res, n);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        help(0, nums, ans, res, n);
        return res;
    }
};