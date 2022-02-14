// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

class Solution
{
public:
    vector<string> res;
    void help(vector<vector<int>> &m, int i, int j, int n, string ans)
    {
        if (i < 0 || j < 0 || i > n - 1 || j > n - 1 || m[i][j] == 0)
        {
            return;
        }
        if (i == n - 1 && j == n - 1)
        {
            res.push_back(ans);
            return;
        }
        m[i][j] = 0;
        help(m, i, j + 1, n, ans + "R");
        help(m, i, j - 1, n, ans + "L");
        help(m, i + 1, j, n, ans + "D");
        help(m, i - 1, j, n, ans + "U");
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes her
        help(m, 0, 0, n, "");
        return res;
    }
};
