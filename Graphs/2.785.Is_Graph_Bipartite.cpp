//https://leetcode.com/problems/is-graph-bipartite/

//Time complexity-> O(V+E)
// space complexity-> O(V)

class Solution
{
public:
    bool checkbfs(int node, vector<int> &color, vector<vector<int>> &adj)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            for (auto it : adj[val])
            {
                if (color[it] == -1)
                {
                    q.push(it);
                    color[it] = 1 - color[val];
                }
                else if (color[it] == color[val])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (checkbfs(i, color, graph) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};