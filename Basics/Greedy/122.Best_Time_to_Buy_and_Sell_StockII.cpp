//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// this is also greedy solution
// more than one transactions are allowed
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int ans = 0, mini = prices[0];
        for (int i = 1; i < n; i++)
        {
            if (prices[i] < mini)
            {
                mini = prices[i];
            }
            else
            {
                ans += (prices[i] - mini);
                mini = prices[i];
            }
        }
        return ans;
    }
};