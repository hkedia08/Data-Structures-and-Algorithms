//https://practice.geeksforgeeks.org/problems/bipartite-graph/1/

// using bfs
bool bfs(int val, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(val);
    color[val] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> color(V + 1, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (bfs(i, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}
}
;

// using dfs
class Solution
{
public:
    bool dfs(int node, vector<int> &color, vector<int> adj[])
    {
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                if (dfs(it, color, adj) == false)
                {
                    return false;
                }
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 1;
                if (dfs(i, color, adj) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
