//https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1#

class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<vector<int>> result;
        for (int i = 0; i < V; i++)
        {
            vector<int> v;
            v.push_back(i);
            for (auto it : adj[i])
            {
                v.push_back(it);
            }
            result.push_back(v);
        }
        return result;
    }
};
