// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

// https://www.codingninjas.com/codestudio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        // Your code here
        unordered_map<int, int> m;
        int sum = 0;
        int largest = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum == 0)
            {
                largest = max(largest, i + 1);
            }
            if (m.find(sum) != m.end())
            {
                int len = i - m[sum];
                largest = max(largest, len);
            }
            else
            {
                m[sum] = i;
            }
        }
        return largest;
    }
};
