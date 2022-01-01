//https://leetcode.com/problems/rotate-array/

// always check edge cases here k=k%n
// always check for n=0 and n=1

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = (k + n) % n;
        int end1 = n - k;
        reverse(nums.begin(), nums.begin() + end1);
        reverse(nums.begin() + end1, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
