// https://leetcode.com/problems/set-matrix-zeroes/

// solution -> https://youtu.be/djt9mwch-Xo
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0, y = 0;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                y = 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
                x = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (y == 1)
        {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        if (x == 1)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};

// better approach
vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> result;
    for (int i = 0; i < n; i++)
    {
        vector<long long int> next(i + 1, 1);
        for (long long int j = 1; j < i; j++)
        {
            next[j] = result[i - 1][j] + result[i - 1][j - 1];
        }
        result.push_back(next);
    }
    return result;
}
