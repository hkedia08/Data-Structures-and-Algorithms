//https://leetcode.com/problems/delete-and-earn/

// It is just variation of house-robber problem
class Solution
{
public:
    int helper(int i, vector<int> &dp, vector<int> &cost)
    {
        if (i >= cost.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int op1 = (cost[i] * i) + helper(i + 2, dp, cost);
        int op2 = helper(i + 1, dp, cost);
        dp[i] = max(op1, op2);
        return dp[i];
    }
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        int range = *max_element(nums.begin(), nums.end());
        vector<int> dp(range + 1, -1);
        vector<int> numscount(range + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            numscount[nums[i]]++;
        int ans = helper(0, dp, numscount);
        return ans;
    }
};
