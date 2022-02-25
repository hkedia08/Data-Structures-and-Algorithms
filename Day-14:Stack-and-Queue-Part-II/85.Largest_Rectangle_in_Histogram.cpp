// https://leetcode.com/problems/largest-rectangle-in-histogram/

// using stack and using two parse

class Solution
{
public:
    void pse(vector<int> &heights, vector<int> &left)
    {
        stack<int> s;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
                left[i] = -1;
            else
                left[i] = s.top();
            s.push(i);
        }
        while (!s.empty())
            s.pop();
    }
    void nse(vector<int> &heights, vector<int> &right)
    {
        stack<int> s;
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (s.empty() == true)
            {
                right[i] = heights.size();
            }
            else
                right[i] = s.top();
            s.push(i);
        }
        while (!s.empty())
            s.pop();
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        pse(heights, left);
        nse(heights, right);
        int maxans = 0;
        for (int i = 0; i < n; i++)
        {
            maxans = max(maxans, (right[i] - left[i] - 1) * heights[i]);
        }
        return maxans;
    }
};
class Solution
{
public:
    void pse(vector<int> &heights, vector<int> &left)
    {
        stack<int> s;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
                left[i] = -1;
            else
                left[i] = s.top();
            s.push(i);
        }
        while (!s.empty())
            s.pop();
    }
    void nse(vector<int> &heights, vector<int> &right)
    {
        stack<int> s;
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (s.empty() == true)
            {
                right[i] = heights.size();
            }
            else
                right[i] = s.top();
            s.push(i);
        }
        while (!s.empty())
            s.pop();
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        pse(heights, left);
        nse(heights, right);
        int maxans = 0;
        for (int i = 0; i < n; i++)
        {
            maxans = max(maxans, (right[i] - left[i] - 1) * heights[i]);
        }
        return maxans;
    }
};
