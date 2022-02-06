// https://leetcode.com/problems/unique-paths/

// top down
class Solution
{
public:
    int paths(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = paths(i + 1, j, m, n, dp) + paths(i, j + 1, m, n, dp);
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return paths(0, 0, m, n, dp);
    }
};

// tabulation apprpoach
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int matrix[m][n];
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        return matrix[m - 1][n - 1];
    }
};