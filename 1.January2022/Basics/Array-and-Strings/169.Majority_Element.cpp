// Moore voting algo
// https://leetcode.com/problems/majority-element/
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int val = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (val == nums[i])
                count++;
            else
                count--;
            if (count == 0)
            {
                val = nums[i];
                count = 1;
            }
        }
        return val;
    }
};
