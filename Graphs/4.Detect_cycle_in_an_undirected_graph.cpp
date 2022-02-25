//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

// BFS approach
class Solution
{
public:
    bool bfs(int val, vector<int> &visited, vector<int> adj[], vector<int> &parent)
    {
        queue<int> q;
        parent[val] = -1;
        q.push(val);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            visited[node] = 1;
            for (auto it : adj[node])
            {
                if (visited[it] == 0)
                {
                    visited[it] = 1;
                    parent[it] = node;
                    q.push(it);
                }
                else if (it != parent[node])
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);
        vector<int> parent(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (bfs(i, visited, adj, parent) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// DFS approach
class Solution
{
public:
    bool dfs(int node, vector<int> &visited, vector<int> adj[], int parent)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                visited[it] = 1;
                if (dfs(it, visited, adj, node) == true)
                {
                    return true;
                }
            }
            else if (it != parent)
            {
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, adj, -1) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
