// https://leetcode.com/problems/maximum-subarray/
// https://www.codingninjas.com/codestudio/problems/630526?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// solution -> https://youtu.be/w_KEocd__20
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxsum = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxsum = max(maxsum, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxsum;
    }
};