// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            // so we are applying binary search in sorted region
            else if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && nums[mid] >= target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (nums[mid] <= nums[high])
            {
                if (target >= nums[mid] && nums[high] >= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};