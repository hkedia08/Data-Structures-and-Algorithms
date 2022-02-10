// https://leetcode.com/problems/trapping-rain-water/

// approach one using two loops
// approach two using prefix and suffix array

// approach using two pointer
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int low = 0;
        int high = n - 1;
        int left_max = height[0];
        int right_max = height[n - 1];
        long long ans = 0;
        while (low <= high)
        {
            if (left_max < right_max)
            {
                if (height[low] > left_max)
                    left_max = height[low];
                else
                {
                    ans += (left_max - height[low]);
                    low++;
                }
            }
            else
            {
                if (height[high] > right_max)
                    right_max = height[high];
                else
                {
                    ans += (right_max - height[high]);
                    high--;
                }
            }
        }
        return ans;
    }
};