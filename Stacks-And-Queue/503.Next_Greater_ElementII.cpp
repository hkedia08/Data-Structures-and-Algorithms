//https://leetcode.com/problems/next-greater-element-ii/

// everything is just same as next greater element in this ngt is not -1

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        vector<int> result;
        int n = nums.size();
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (st.size() > 0 && st.top() <= nums[i % n])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                if (i < n)
                    result.push_back(-1);
            }
            else
            {
                if (i < n)
                    result.push_back(st.top());
            }
            st.push(nums[i % n]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};