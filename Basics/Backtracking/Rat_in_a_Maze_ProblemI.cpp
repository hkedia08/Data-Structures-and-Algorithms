// Time complexity - O(4^(M*N))
// Space complexity(M*N)

//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution
{
    void mazepath(int i, int j, int n, vector<vector<int>> &visited, vector<vector<int>> &m, string path, vector<string> &ans)
    {
        // edge cases
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] == 1 || m[i][j] == 0)
        {
            return;
        }
        // this is the end of matrix
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(path);
            return;
        }
        // mark the visited
        visited[i][j] = 1;
        mazepath(i + 1, j, n, visited, m, path + "D", ans);
        mazepath(i, j - 1, n, visited, m, path + "L", ans);
        mazepath(i, j + 1, n, visited, m, path + "R", ans);
        mazepath(i - 1, j, n, visited, m, path + "U", ans);
        // unmark the visited one
        visited[i][j] = 0;
        return;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<vector<int>> visited = m;
        for (int i = 0; i < visited.size(); i++)
        {
            for (int j = 0; j < visited[i].size(); j++)
            {
                visited[i][j] = 0;
            }
        }
        vector<string> ans;
        mazepath(0, 0, n, visited, m, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
