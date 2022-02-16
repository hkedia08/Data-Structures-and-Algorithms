// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://www.codingninjas.com/codestudio/problems/893405?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        int lbuy = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            maxprofit = max(maxprofit, prices[i] - lbuy);
            lbuy = min(prices[i], lbuy);
        }
        return maxprofit;
    }
};