//https://leetcode.com/problems/longest-increasing-subsequence/

// O(N^2) time complexity
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++)
        {
            dp[i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};

//O(NLOGN)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > lis.back())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[idx] = nums[i];
            }
        }
        return lis.size();
    }
};
