//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/#

void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &storedfs)
{
    // this is the part before entering the node vertex
    visited[node] = 1;
    storedfs.push_back(node);
    for (auto child : adj[node])
    {
        // this is before entering child node
        if (!visited[child])
        {
            dfs(child, visited, adj, storedfs);
        }
        // this is after coming out of child node
    }
    // this is after coming out of parent node
}
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> visited(V, 0);
    vector<int> storedfs;
    dfs(0, visited, adj, storedfs);
    return storedfs;
}
