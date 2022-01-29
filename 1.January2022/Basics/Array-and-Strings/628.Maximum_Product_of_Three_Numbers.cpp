//https://leetcode.com/problems/maximum-product-of-three-numbers/

// intution based problem just think mathematically
// Time complexity is O(Nlogn)
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int option1 = nums[0] * nums[1] * nums[n - 1];
        int option2 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int ans = max(option1, option2);
        return ans;
    }
};

// instead of sorting we can use  5 variable to solve this problem

// O(N) solution

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int min1 = INT_MAX;
        int min2 = min1;
        int max1 = INT_MIN;
        int max2 = max1;
        int max3 = max2;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            // for maximum
            if (val >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = val;
            }
            else if (val >= max2)
            {
                max3 = max2;
                max2 = val;
            }
            else if (val >= max3)
            {
                max3 = val;
            }

            // for minimum
            if (val <= min1)
            {
                min2 = min1;
                min1 = val;
            }
            else if (val <= min2)
            {
                min2 = val;
            }
        }
        // finding product
        int option1 = min1 * min2 * max1;
        int option2 = max1 * max2 * max3;
        int ans = max(option1, option2);
        return ans;
    }
};
