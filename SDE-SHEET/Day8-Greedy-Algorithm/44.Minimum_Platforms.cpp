// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int start[], int end[], int n)
    {
        sort(start, start + n);
        sort(end, end + n);
        int i, j;
        i = 0, j = 0;
        int count = 0;
        int maxcount = 0;
        while (i < n)
        {
            if (start[i] <= end[j])
            {
                count++;
                maxcount = max(maxcount, count);
                i++;
            }
            else
            {
                while (end[j] < start[i])
                {
                    j++;
                    count--;
                }
            }
        }
        return maxcount;
    }
};
