// https://leetcode.com/problems/max-consecutive-ones/

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        int i = 0;
        int mcount = 0;
        while (i < n)
        {
            if (nums[i] == 1)
            {
                count++;
                mcount = max(mcount, count);
            }
            else
            {
                count = 0;
            }
            i++;
        }
        return mcount;
    }
};
