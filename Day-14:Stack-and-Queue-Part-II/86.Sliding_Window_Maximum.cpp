// https://leetcode.com/problems/sliding-window-maximum/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            while ((!dq.empty()) && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        vector<int> result;
        result.push_back(dq.front());
        for (int i = k; i < n; i++)
        {
            if (dq.front() == nums[i - k])
                dq.pop_front();
            while ((!dq.empty()) && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            result.push_back(dq.front());
        }
        return result;
    }
};