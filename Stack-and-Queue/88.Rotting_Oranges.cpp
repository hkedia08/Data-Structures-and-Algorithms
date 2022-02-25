// https://leetcode.com/problems/rotting-oranges/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int total = 0;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    total++;
                }
                else if (grid[i][j] == 1)
                    total++;
            }
        }
        int day = 0;
        while (!q.empty())
        {
            int k = q.size();
            count += k;
            while (k--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x - 1 >= 0 && grid[x - 1][y] == 1)
                {
                    q.push({x - 1, y});
                    grid[x - 1][y] = 2;
                }
                if (x + 1 < n && grid[x + 1][y] == 1)
                {
                    q.push({x + 1, y});
                    grid[x + 1][y] = 2;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1)
                {
                    q.push({x, y - 1});
                    grid[x][y - 1] = 2;
                }
                if (y + 1 < m && grid[x][y + 1] == 1)
                {
                    q.push({x, y + 1});
                    grid[x][y + 1] = 2;
                }
            }
            if (!q.empty())
                day++;
        }
        if (total != count)
            return -1;
        return day;
    }
};