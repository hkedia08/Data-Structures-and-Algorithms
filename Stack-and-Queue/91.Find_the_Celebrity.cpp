// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        while (s.size() >= 2)
        {
            int i = s.top();
            s.pop();
            int j = s.top();
            s.pop();
            if (M[i][j] == 1)
            {
                s.push(j);
            }
            else
                s.push(i);
        }
        int pot = s.top();
        s.pop();
        int ans = pot;
        for (int j = 0; j < n; j++)
        {
            if (M[pot][j] == 1)
                return -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != pot)
                if (M[i][pot] == 0)
                    return -1;
        }
        return pot;
    }
};