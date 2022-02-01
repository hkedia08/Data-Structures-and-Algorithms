//https://leetcode.com/problems/min-cost-climbing-stairs/

// top down
class Solution
{
public:
    int helper(int i, vector<int> &dp, vector<int> &cost)
    {
        if (i >= cost.size())
        {
            return 0;
        }
        if (dp[i] != 0)
            return dp[i];
        int dp1 = helper(i + 1, dp, cost);
        int dp2 = helper(i + 2, dp, cost);
        return dp[i] = min(dp1, dp2) + cost[i];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        int ans = min(helper(0, dp, cost), helper(1, dp, cost));
        return ans;
    }
};

// bottom up
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i <= n; i++)
        {
            if (i == n)
                dp[i] = min(dp[i - 1], dp[i - 2]);
            else
                dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return dp[n];
    }
};
