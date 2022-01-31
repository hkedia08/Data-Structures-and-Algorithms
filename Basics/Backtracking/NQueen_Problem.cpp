//https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/
class Solution
{
public:
    bool isSafe(int row, int col, vector<vector<int>> &store, int n)
    {
        for (int j = 0; j < n; j++)
        {
            if (store[row][j] == 1)
            {
                return false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (store[i][col] == 1)
            {
                return false;
            }
        }
        int r = row;
        int c = col;
        // upper left
        while (r >= 0 && c >= 0)
        {
            if (store[r][c] == 1)
            {
                return false;
            }
            r--;
            c--;
        }
        // upper right
        r = row;
        c = col;
        while (r >= 0 && c < n)
        {
            if (store[r][c] == 1)
            {
                return false;
            }
            r--;
            c++;
        }
        // lower left
        r = row;
        c = col;
        while (r < n && c >= 0)
        {
            if (store[r][c] == 1)
            {
                return false;
            }
            r++;
            c--;
        }
        // lower right
        r = row;
        c = col;
        while (r < n && c < n)
        {
            if (store[r][c] == 1)
            {
                return false;
            }
            r++;
            c++;
        }
        return true;
    }

    void helper(int row, int n, vector<vector<int>> &board, vector<vector<int>> &store, vector<int> path)
    {
        if (row == n)
        {
            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (store[i][j] == 1)
                    {
                        path.push_back(i + 1);
                    }
                }
            }
            board.push_back(path);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col, store, n))
            {
                // path.push_back(row+1);
                store[row][col] = 1;
                helper(row + 1, n, board, store, path);
                store[row][col] = 0;
                //  path.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<int> path;
        vector<vector<int>> board;
        vector<vector<int>> store(n, vector<int>(n, 0));
        helper(0, n, board, store, path);
        sort(board.begin(), board.end());
        return board;
    }
};
//https://leetcode.com/problems/n-queens/

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> store, int n)
    {
        for (int j = 0; j < n; j++)
        {
            if (store[row][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (store[i][col] == 'Q')
            {
                return false;
            }
        }
        int r = row;
        int c = col;
        // upper left
        while (r >= 0 && c >= 0)
        {
            if (store[r][c] == 'Q')
            {
                return false;
            }
            r--;
            c--;
        }
        // upper right
        r = row;
        c = col;
        while (r >= 0 && c < n)
        {
            if (store[r][c] == 'Q')
            {
                return false;
            }
            r--;
            c++;
        }
        // lower left
        r = row;
        c = col;
        while (r < n && c >= 0)
        {
            if (store[r][c] == 'Q')
            {
                return false;
            }
            r++;
            c--;
        }
        // lower right
        r = row;
        c = col;
        while (r < n && c < n)
        {
            if (store[r][c] == 'Q')
            {
                return false;
            }
            r++;
            c++;
        }
        return true;
    }
    void helper(int row, int n, vector<vector<string>> &board, vector<string> store)
    {
        if (row == n)
        {
            board.push_back(store);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(row, col, store, n))
            {
                store[row][col] = 'Q';
                helper(row + 1, n, board, store);
                store[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> board;
        vector<string> store(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            store[i] = s;
        }
        helper(0, n, board, store);
        return board;
    }
};
