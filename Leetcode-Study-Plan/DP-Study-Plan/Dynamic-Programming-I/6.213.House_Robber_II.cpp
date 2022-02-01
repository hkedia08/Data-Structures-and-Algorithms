//https://leetcode.com/problems/house-robber-ii/

// apply house robbber concept two times

// one for i=0 to i=n-1 and other for i=1 to i==n
// because first and last cannot be taken together
class Solution
{
public:
    int helper(int i, vector<int> &dp, vector<int> &cost, int n)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int op1 = cost[i] + helper(i + 2, dp, cost, n);
        int op2 = helper(i + 1, dp, cost, n);
        return dp[i] = max(op1, op2);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        int res1 = helper(0, dp1, nums, n - 1);
        int res2 = helper(1, dp2, nums, n);
        return max(res1, res2);
    }
};