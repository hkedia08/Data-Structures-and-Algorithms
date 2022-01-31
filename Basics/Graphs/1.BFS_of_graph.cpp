//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Time complexity -> O(V+E)
// space complexity -> O(V)

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        queue<int> q;
        vector<int> visited(V, 0);
        vector<int> result;
        q.push(0);
        visited[0] = 1;
        while (!q.empty())
        {
            int element = q.front();
            q.pop();
            result.push_back(element);
            for (auto it : adj[element])
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
