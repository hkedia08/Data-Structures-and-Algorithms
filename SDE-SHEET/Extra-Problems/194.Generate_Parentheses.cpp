// https://leetcode.com/problems/generate-parentheses/
// https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/

class Solution
{
public:
    void help(vector<string> &res, int open, int close, int n, string s)
    {
        if (open + close == 2 * n)
        {
            res.push_back(s);
            return;
        }
        if (open < n)
        {
            help(res, open + 1, close, n, s + "(");
        }
        if (close < open)
        {
            help(res, open, close + 1, n, s + ")");
        }
        return;
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        help(res, 0, 0, n, "");
        return res;
    }
};