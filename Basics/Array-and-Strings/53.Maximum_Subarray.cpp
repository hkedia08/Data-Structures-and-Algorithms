//https://leetcode.com/problems/maximum-subarray/

// greedy algorithim
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        int maxsum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum = max(sum, nums[i]);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};

// Using divide and conquer approach
