// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1#

class Solution
{
public:
    void rec(int i, string &digits, string temp, map<int, string> &m, vector<string> &res)
    {
        if (i == digits.size())
        {
            res.push_back(temp);
            return;
        }
        string val = m[digits[i] - '0'];
        for (int j = 0; j < val.size(); j++)
        {
            rec(i + 1, digits, temp + val[j], m, res);
        }
        return;
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        vector<string> res;
        rec(0, digits, "", m, res);
        return res;
    }
};

// another solution

class Solution
{
public:
    vector<string> help(int i, string &digits, map<int, string> m)
    {
        if (i == digits.size())
        {
            vector<string> res;
            res.push_back("");
            return res;
        }
        vector<string> res = help(i + 1, digits, m);
        vector<string> ans;
        for (auto a : m[digits[i] - '0'])
        {
            for (auto x : res)
            {
                ans.push_back(a + x);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        return help(0, digits, m);
    }
};