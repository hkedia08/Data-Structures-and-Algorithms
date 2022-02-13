// https://leetcode.com/problems/sudoku-solver/

// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1/#

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solveboard(board);
    }
    bool solveboard(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, row, col, c) == true)
                        {
                            board[row][col] = c;
                            if (solveboard(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
            {
                return false;
            }
            if (board[row][i] == c)
            {
                return false;
            }
        }
        for (int r = sr; r < sr + 3; r++)
        {
            for (int co = sc; co < sc + 3; co++)
            {
                if (board[r][co] == c)
                {
                    return false;
                }
            }
        }
        return true;
    }
};