// https://youtu.be/zPtI8q9gvX8

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

class Solution
{
public:
    static bool cmp(Job &a, Job &b)
    {
        return (a.profit) > (b.profit);
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        int deadline = 0;
        int count_job = 0;
        int max_profit = 0;
        for (int i = 0; i < n; i++)
        {
            deadline = max(deadline, arr[i].dead);
        }
        sort(arr, arr + n, cmp);
        vector<int> dd(deadline + 1, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (dd[j] == -1)
                {
                    count_job++;
                    max_profit += arr[i].profit;
                    dd[j] = i;
                    break;
                }
            }
        }
        return {count_job, max_profit};
    }
};