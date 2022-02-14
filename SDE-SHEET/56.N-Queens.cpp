// https://leetcode.com/problems/n-queens/

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            else
            {
                row--;
                col--;
            }
        }
        row = duprow;
        col = dupcol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            else
            {
                col--;
            }
        }
        col = dupcol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            else
            {
                row++;
                col--;
            }
        }
        return true;
    }

    void solveboard(int col, vector<vector<string>> &res, vector<string> &board, int n)
    {
        if (col == n)
        {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solveboard(col + 1, res, board, n);
                board[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solveboard(0, res, board, n);
        return res;
    }
};