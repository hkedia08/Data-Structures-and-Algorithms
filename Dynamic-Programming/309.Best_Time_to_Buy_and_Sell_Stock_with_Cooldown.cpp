//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// this problem is same as transaction fees onlt minute difference

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[n][3];
        dp[0][0] = -(prices[0]);
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return dp[n - 1][1];
    }
};
