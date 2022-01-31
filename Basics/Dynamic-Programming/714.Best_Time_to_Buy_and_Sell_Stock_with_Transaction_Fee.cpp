//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// dp solution can be generalized for all buy and sell stock problem
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -(prices[0]);
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[n - 1][1];
    }
};

// greedy solution

// approach is same just done using variables
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int obsf = -prices[0];
        int ossf = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            int nbsf = 0;
            int nssf = 0;
            if (ossf - prices[i] > obsf)
            {
                nbsf = ossf - prices[i];
            }
            else
            {
                nbsf = obsf;
            }
            if (obsf + prices[i] - fee > ossf)
            {
                nssf = obsf + prices[i] - fee;
            }
            else
            {
                nssf = ossf;
            }
            obsf = nbsf;
            ossf = nssf;
        }
        return ossf;
    }
};
