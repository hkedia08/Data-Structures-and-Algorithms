// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int low = 0;
        int high = low + 1;
        while (high < n)
        {
            if (nums[low] == nums[high])
            {
                while (high < n && nums[low] == nums[high])
                    high++;
            }
            else
            {
                low++;
                nums[low] = nums[high];
                high++;
            }
        }
        return low + 1;
    }
};