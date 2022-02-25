// https://leetcode.com/problems/merge-intervals/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        // this is the edge case
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
        {
            int m = result.size();
            if (intervals[i][0] <= result[m - 1][1])
            {
                // this is the edge case
                result[m - 1][1] = max(intervals[i][1], result[m - 1][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};