//https://leetcode.com/problems/house-robber/

// brute force
class Solution
{
public:
    int rob(vector<int> &cost)
    {
        int n = cost.size();
        if (n == 1)
        {
            return cost[0];
        }
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            for (int j = i - 2; j >= 0; j--)
            {
                dp[i] = max(dp[i], dp[j] + cost[i]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// top down
class Solution
{
public:
    int helper(int i, vector<int> &dp, vector<int> &cost)
    {
        if (i >= cost.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int op1 = cost[i] + helper(i + 2, dp, cost);
        int op2 = helper(i + 1, dp, cost);
        dp[i] = max(op1, op2);
        return dp[i];
    }
    int rob(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = helper(0, dp, cost);
        return ans;
    }
};

//bottom up
class Solution
{
public:
    int rob(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 2, -1);
        dp[n + 1] = 0;
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int op1 = cost[i] + dp[i + 2];
            int op2 = dp[i + 1];
            dp[i] = max(op1, op2);
        }
        return dp[0];
    }
};
