// https://leetcode.com/problems/permutations/

// map approach
class Solution
{
public:
    void help(vector<int> &nums, vector<int> &ans, vector<vector<int>> &res, int frequency[])
    {
        if (ans.size() == nums.size())
        {
            res.push_back(ans);
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ans;
        int n = nums.size();
        int frequency[n];
        for (int i = 0; i < n; i++)
            frequency[i] = 0;
        help(nums, ans, res, frequency);
        return res;
    }
};

// without space
class Solution
{
public:
    void help(int idx, vector<int> &nums, vector<vector<int>> &res)
    {
        if (idx == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            help(idx + 1, nums, res);
            swap(nums[i], nums[idx]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        help(0, nums, res);
        return res;
    }
};