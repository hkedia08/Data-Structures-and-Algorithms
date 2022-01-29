//https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        map<string, int> hm;
        for (auto it : words)
        {
            hm[it]++;
        }
        // this was to keep track of ans
        int ans = 0;
        // to keep same and reverse string
        string front, back;
        // just for one middle only when both elements are same
        bool middle = false;
        for (auto it : hm)
        {
            string front = it.first;
            string back = front;
            reverse(back.begin(), back.end());
            if (hm.find(back) != hm.end())
            {
                int val = 0;
                if (front != back)
                {
                    val = min(hm[front], hm[back]);
                    val = val * 2;
                }
                else
                {
                    // this was to keep even number
                    val = hm[front] / 2;
                    val = val * 2;
                    // if odd is there then it can contribute at once to middle
                    if (hm[front] % 2 == 1)
                    {
                        if (middle == false)
                        {
                            val += 1;
                            middle = true;
                        }
                    }
                }
                hm[front] = 0;
                hm[back] = 0;
                ans += val;
            }
        }
        // as there are two elements for each string
        return ans * 2;
    }
};