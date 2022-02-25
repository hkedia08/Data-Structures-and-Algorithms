//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

// we are using two vector one for visited and other for whether we are visiting for same path or not
// if we are on same path and we found node again then there is cycle

// basically we checking whether there back edge or not
class Solution
{
public:
    bool dfs(int node, vector<int> &visited, vector<int> &dfsvisited, vector<int> adj[])
    {
        visited[node] = 1;

        // for same path
        dfsvisited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfs(it, visited, dfsvisited, adj) == true)
                {
                    return true;
                }
            }
            // if node is already visited using same path then it means there cycle
            else if (dfsvisited[it] == 1)
            {
                return true;
            }
        }
        // coming back from that path
        dfsvisited[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> visited(V + 1, 0);
        vector<int> dfsvisited(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, dfsvisited, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
