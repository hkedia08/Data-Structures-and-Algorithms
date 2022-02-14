// https://leetcode.com/problems/palindrome-partitioning/

class Solution
{
public:
    void help(int indx, string s, vector<string> &path, vector<vector<string>> &result)
    {
        if (indx == s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = indx; i < s.size(); i++)
        {
            if (isPalindrome(s, indx, i) == true)
            {
                path.push_back(s.substr(indx, i - indx + 1));
                help(i + 1, s, path, result);
                path.pop_back();
            }
        }
        return;
    }
    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;
        help(0, s, path, result);
        return result;
    }
};