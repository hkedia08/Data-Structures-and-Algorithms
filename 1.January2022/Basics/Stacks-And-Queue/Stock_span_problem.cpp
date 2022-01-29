//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/#

class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        stack<pair<int, int>> st;
        vector<int> result;
        reverse(price, price + n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() > 0 && st.top().first <= price[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(st.top().second);
            }
            st.push({price[i], n - i - 1});
        }
        for (int i = 0; i < n; i++)
        {
            result[i] = i - result[i];
        }
        return result;
    }
};
