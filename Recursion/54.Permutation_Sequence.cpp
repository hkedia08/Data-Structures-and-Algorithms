// https://leetcode.com/problems/permutation-sequence/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fac = 1;
        vector<int> nums;
        string ans = "";
        for (int i = 1; i < n; i++)
        {
            fac = fac * i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k - 1;
        while (true)
        {
            ans = ans + to_string(nums[k / fac]);
            nums.erase(nums.begin() + k / fac);
            if (nums.size() == 0)
                break;
            k = k % fac;
            fac = fac / nums.size();
        }
        return ans;
    }
};