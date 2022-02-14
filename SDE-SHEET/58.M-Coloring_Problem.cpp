// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

bool isSafe(bool graph[101][101], int node, int color[], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (node != k && graph[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101], int node, int color[], int m, int n)
{
    if (node == n)
        return true;
    for (int col = 1; col <= m; col++)
    {
        if (isSafe(graph, node, color, n, col) == true)
        {
            color[node] = col;
            if (solve(graph, node + 1, color, m, n))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    int color[n + 1] = {0};
    if (solve(graph, 0, color, m, n) == true)
        return true;
    return false;
}
