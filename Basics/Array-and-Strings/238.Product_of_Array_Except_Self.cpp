// using concept of prefix and suffix sum
// this take O(N) extra space
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int prefix[n];
        int suffix[n];
        prefix[0] = 1;
        suffix[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        vector<int> product(n);
        for (int i = 0; i < n; i++)
        {
            product[i] = prefix[i] * suffix[i];
        }
        return product;
    }
};

// for O(1) space

// ans array is not considerd as extra space
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * suffix;
            suffix = suffix * nums[i];
        }
        return ans;
    }
};
