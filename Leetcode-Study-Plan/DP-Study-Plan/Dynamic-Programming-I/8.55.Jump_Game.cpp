//https://leetcode.com/problems/jump-game/

// greedy approach
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // start from last and check whether we can reach that index or not
        int n = nums.size();
        int index = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if ((i + nums[i]) >= index)
            {
                index = i;
            }
        }
        if (index == 0)
            return true;
        return false;
    }
};