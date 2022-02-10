// https://leetcode.com/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> v;
        int n = nums.size();
        if (n < 3)
            return v;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    v.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < n && nums[j] == nums[j - 1])
                        j++;
                    while (k >= 0 && nums[k] == nums[k + 1])
                        k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - ])
                i++;
        }
        return v;
    }
};