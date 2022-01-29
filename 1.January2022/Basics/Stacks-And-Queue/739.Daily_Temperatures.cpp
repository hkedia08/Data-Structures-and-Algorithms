//https://leetcode.com/problems/daily-temperatures/

// time O(N) and space O(N)

// variation of next greater element
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> st;
        vector<int> result;
        int n = temperatures.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() > 0 && st.top().first <= temperatures[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(st.top().second - i);
            }
            st.push({temperatures[i], i});
        }
        reverse(result.begin(), result.end());
        return result;
    }
};