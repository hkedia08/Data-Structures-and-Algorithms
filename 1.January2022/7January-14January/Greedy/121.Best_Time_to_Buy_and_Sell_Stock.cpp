//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// This is series of buy and sell stock questions

// this is greedy solution only when one transaction is allowed
// time complexity (O(N))
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;
        int ans = 0, mini = prices[0];
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }
};