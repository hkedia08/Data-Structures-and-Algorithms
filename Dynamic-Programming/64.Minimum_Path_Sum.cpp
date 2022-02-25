//https://leetcode.com/problems/minimum-path-sum/

// Greedy will not work

// DP (O(n^2))
#include <bits/stdc++.h>
using namespace std;
int minimum_path_sum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int j = 1; j < m; j++)
    {
        grid[0][j] += grid[0][j - 1];
    }
    for (int i = 1; i < n; i++)
    {
        grid[i][0] += grid[i - 1][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[n - 1][m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            int in;
            cin >> in;
            v.push_back(in);
        }
        grid.push_back(v);
        v.clear();
    }
    int ans = minimum_path_sum(grid);
    cout << ans << endl;
}