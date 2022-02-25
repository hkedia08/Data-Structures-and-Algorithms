// https://leetcode.com/problems/online-stock-span/

// same as finding previous greater element

class StockSpanner
{
public:
    stack<pair<int, int>> s;
    int count;
    StockSpanner()
    {
        s = {};
        count = 0;
    }

    int next(int price)
    {
        while (!s.empty() && s.top().first <= price)
        {
            s.pop();
        }
        count++;
        int ans;
        if (s.empty() == true)
            ans = count;
        else
            ans = count - s.top().second;
        s.push({price, count});
        return ans;
    }
};
