//https://leetcode.com/problems/russian-doll-envelopes/
//https://www.geeksforgeeks.org/dynamic-programming-building-bridges/

// This problem is application of LIS

//O(N^2) solution
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n + 1, 1);
        // LIS
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                if ((envelopes[i][0] > envelopes[j][0]) && (envelopes[i][1] > envelopes[j][1]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};

// O(N*LOGN)
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] < b[0])
                     return true;
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return false;
             });
        vector<int> lis;
        lis.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++)
        {
            int indx = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
            if (indx == lis.size())
            {
                lis.push_back(envelopes[i][1]);
            }
            else
            {
                lis[indx] = envelopes[i][1];
            }
        }
        return lis.size();
    }
};

//  other version of compartor
class Solution
{
public:
    bool static compare(const vector<int> &a, vector<int> &b)
    {
        if (a[0] < b[0])
        {
            return true;
        }
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return false;
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> lis;
        lis.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++)
        {
            int indx = lower_bound(lis.begin(), lis.end(), envelopes[i][1]) - lis.begin();
            if (indx == lis.size())
            {
                lis.push_back(envelopes[i][1]);
            }
            else
            {
                lis[indx] = envelopes[i][1];
            }
        }
        return lis.size();
    }
};