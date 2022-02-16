// https://leetcode.com/problems/single-element-in-a-sorted-array/
// https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1/#
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        // base case
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        int low, high, mid;
        low = 0, high = n - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if (nums[mid] == nums[mid - 1])
            {
                int lc = (mid - low + 1);
                if (lc % 2 == 0)
                    low = mid + 1;
                else
                    high = mid - 2;
            }
            else if (nums[mid] == nums[mid + 1])
            {
                int lr = (high - mid + 1);
                if (lr % 2 == 0)
                    high = mid - 1;
                else
                    low = mid + 2;
            }
        }
        return -1;
    }
};
