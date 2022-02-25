// https://leetcode.com/problems/min-stack/

// solution using pair
class MinStack
{
public:
    stack<pair<int, int>> s;
    MinStack()
    {
        while (!s.empty())
            s.pop();
    }

    void push(int val)
    {
        // to avoid overflow
        int mini;
        if (s.empty())
            mini = val;
        else
        {
            mini = min(s.top().second, val);
        }
        s.push(make_pair(val, mini));
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};

// this problem can be solved using two stack
// one mathematical formula is also there to sovle this
