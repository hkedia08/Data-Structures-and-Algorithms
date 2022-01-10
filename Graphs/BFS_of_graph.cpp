//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

// level order traversal is != bfs

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        queue<int> q;
        vector<int> result;
        vector<int> visited(V + 1, 0);
        q.push(0);
        result.push_back(0);
        visited[0] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto it : adj[x])
            {
                if (visited[it] == 0)
                {
                    q.push(it);
                    result.push_back(it);
                    visited[it] = 1;
                }
            }
        }
        return result;
    }
};