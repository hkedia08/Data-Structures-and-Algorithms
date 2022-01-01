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
