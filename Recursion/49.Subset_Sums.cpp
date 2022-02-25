// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
public:
    void help(int idx, vector<int> &nums, int sum, vector<int> &res, int n)
    {
        res.push_back(sum);
        for (int i = idx; i < n; i++)
        {
            sum += nums[i];
            help(i + 1, nums, sum, res, n);
            sum -= nums[i];
        }
    }
    vector<int> subsetSums(vector<int> nums, int n)
    {
        vector<int> res;
        help(0, nums, 0, res, n);
        return res;
    }
};