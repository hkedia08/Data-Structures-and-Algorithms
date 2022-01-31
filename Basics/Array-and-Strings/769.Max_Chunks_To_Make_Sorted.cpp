//https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution
{
public:
    // goal is to put each element in its correct position
    int maxChunksToSorted(vector<int> &arr)
    {
        int chunks = 0;
        int maximumelement = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            maximumelement = max(maximumelement, arr[i]);
            if (maximumelement == i)
            {
                chunks++;
            }
        }
        return chunks;
    }
};

// another solution is to keep sum and indexsum variable and check when they become equal then increase the chunks

// best approach is using leftmax and rightmin
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> rightMin(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; i--)
        {
            rightMin[i] = min(arr[i], rightMin[i + 1]);
        }
        int leftMax = INT_MIN;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            leftMax = max(leftMax, arr[i]);
            if (leftMax <= rightMin[i + 1])
            {
                count++;
            }
        }
        return count;
    }
};