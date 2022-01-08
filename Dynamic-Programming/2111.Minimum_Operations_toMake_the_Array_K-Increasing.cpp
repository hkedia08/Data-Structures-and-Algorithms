//https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/

// Time complexity O(NLONG)
// application of LIS

class Solution
{
    int lengthoflis(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= lis.back())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                int idx = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[idx] = nums[i];
            }
        }
        return lis.size();
    }

public:
    int kIncreasing(vector<int> &arr, int k)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            vector<int> lis;
            for (int j = i; j < n; j = j + k)
            {
                lis.push_back(arr[j]);
            }
            int lengthlis = lengthoflis(lis);
            ans += (lis.size() - lengthlis);
        }
        return ans;
    }
};