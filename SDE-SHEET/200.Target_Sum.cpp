// https://leetcode.com/problems/target-sum/
class Solution
{
public:
    void help(int indx, vector<int> &nums, int target, int &count, int sum)
    {
        if (indx == nums.size())
        {
            if (sum == target)
            {
                count++;
            }
            return;
        }
        sum += nums[indx];
        help(indx + 1, nums, target, count, sum);
        sum -= nums[indx];
        sum -= nums[indx];
        help(indx + 1, nums, target, count, sum);
        sum += nums[indx];
        return;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int count = 0;
        help(0, nums, target, count, 0);
        return count;
    }
};