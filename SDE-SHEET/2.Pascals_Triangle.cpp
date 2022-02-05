// https://leetcode.com/problems/pascals-triangle/

// https://www.youtube.com/watch?v=U36MSp4-XVI

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.push_back({1});
        numRows--;
        while (numRows--)
        {
            int n = result.size();
            vector<int> prev = result[n - 1];
            vector<int> next;
            next.push_back(1);
            for (int i = 0; i < prev.size() - 1; i++)
            {
                int sum = prev[i] + prev[i + 1];
                next.push_back(sum);
            }
            next.push_back(1);
            result.push_back(next);
        }
        return result;
    }
};
