//https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        // there can be more than one component in the graph
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
            {
                color[i] = 1;
                q.push(i);
                while (!q.empty())
                {
                    int neigh = q.front();
                    for (auto it : graph[neigh])
                    {
                        if (color[it] == 0)
                        {
                            color[it] = -color[neigh];
                            q.push(it);
                        }
                        else if (color[it] == color[neigh])
                        {
                            return false;
                        }
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};