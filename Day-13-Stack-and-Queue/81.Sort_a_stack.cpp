// https://practice.geeksforgeeks.org/problems/sort-a-stack/1
void sorted(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    else if (stack.top() < num)
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sorted(stack, num);
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    // Your code here
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sorted(stack, num);
}
void SortedStack ::sort()
{
    sortStack(s);
}