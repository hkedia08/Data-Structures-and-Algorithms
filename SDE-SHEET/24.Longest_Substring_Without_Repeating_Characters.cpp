// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int count = 0;
        int longest = 0;
        unordered_map<char, int> m;
        int i = 0, j = 0;
        while (j < n)
        {
            if (m[s[j]] == 0)
            {
                while (j < n && m[s[j]] == 0)
                {
                    m[s[j]]++;
                    count++;
                    longest = max(count, longest);
                    j++;
                }
            }
            else
            {
                while (m[s[j]] > 0)
                {
                    count--;
                    m[s[i]]--;
                    i++;
                }
            }
        }
        return longest;
    }
};