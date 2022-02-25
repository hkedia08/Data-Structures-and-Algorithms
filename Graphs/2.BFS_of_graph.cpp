//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        queue<int> q;
        vector<int> visited(V + 1, 0);
        vector<int> result;
        q.push(0);
        visited[0] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (auto it : adj[node])
            {
                if (visited[it] == 0)
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return result;
    }
};
