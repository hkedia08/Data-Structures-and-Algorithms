// https://leetcode.com/problems/letter-case-permutation/
class Solution
{
public:
    void help(int indx, string s, vector<string> &result)
    {
        if (indx == s.size())
        {
            result.push_back(s);
            return;
        }
        // for lowercase letters
        if (s[indx] >= 97 && s[indx] <= 122)
        {
            s[indx] = toupper(s[indx]);
            help(indx + 1, s, result);
            s[indx] = tolower(s[indx]);
        }
        // for uppercase letters
        else if (s[indx] >= 65 && s[indx] <= 90)
        {
            s[indx] = tolower(s[indx]);
            help(indx + 1, s, result);
            s[indx] = toupper(s[indx]);
        }
        help(indx + 1, s, result);
    }
    vector<string> letterCasePermutation(string s)
    {
        vector<string> result;
        help(0, s, result);
        return result;
    }
};