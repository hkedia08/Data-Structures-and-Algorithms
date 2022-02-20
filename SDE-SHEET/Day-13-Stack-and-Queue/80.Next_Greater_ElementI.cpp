// https://leetcode.com/problems/next-greater-element-i/

class Solution
{
public:
    map<int, int> m;
    void ngt(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i])
                s.pop();
            if (s.size() == 0)
                m[nums[i]] = -1;
            else
                m[nums[i]] = s.top();
            s.push(nums[i]);
        }
    }
    void ngt(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i])
                s.pop();
            if (s.size() == 0)
                m[nums[i]] = -1;
            else
                m[nums[i]] = s.top();
            s.push(nums[i]);
        }
    }
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        ngt(nums2);
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            result.push_back(m[nums1[i]]);
        }
        return result;
    }
};