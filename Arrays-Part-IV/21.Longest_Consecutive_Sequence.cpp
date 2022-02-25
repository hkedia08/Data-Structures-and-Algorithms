// https://leetcode.com/problems/longest-consecutive-sequence/

// NlogN approach
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        // edge case
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int maxcount = 1;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == (nums[i - 1] + 1))
            {
                count++;
                maxcount = max(maxcount, count);
            }
            // edge case
            else if (nums[i] == nums[i - 1])
                continue;
            else
            {
                count = 1;
            }
        }
        return maxcount;
    }
};

// O(N) approach best case
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int longest = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }
        for (auto it : s)
        {
            if (s.find(it - 1) == s.end())
            {
                int val = it;
                int ans = 1;
                while (s.find(val + 1) != s.end())
                {
                    ans++;
                    val++;
                }
                longest = max(longest, ans);
            }
        }
        return longest;
    }
};

// unordered_set may take O(N) in wrost case// O(N) approach best case
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int longest = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }
        for (auto it : s)
        {
            if (s.find(it - 1) == s.end())
            {
                int val = it;
                int ans = 1;
                while (s.find(val + 1) != s.end())
                {
                    ans++;
                    val++;
                }
                longest = max(longest, ans);
            }
        }
        return longest;
    }
};

// unordered_set may take O(N) in wrost case