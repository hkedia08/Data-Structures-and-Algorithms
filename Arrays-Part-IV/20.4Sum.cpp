// https://leetcode.com/problems/4sum/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int low = j + 1;
                int high = n - 1;
                int target2 = target - nums[i] - nums[j];
                while (low < high)
                {
                    vector<int> temp;
                    int two_sum = nums[low] + nums[high];
                    if (two_sum < target2)
                    {
                        low++;
                    }
                    else if (two_sum > target2)
                    {
                        high--;
                    }
                    else
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        result.push_back(temp);
                        low++;
                        high--;
                        while (low < high && nums[low - 1] == nums[low])
                            low++;
                        while (high > low && nums[high] == nums[high + 1])
                            high--;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return result;
    }
};