//https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1, indx = n - 1;
        // fill elements int the vector from the last
        vector<int> result(n, 0);
        while (start <= end)
        {
            int prodt1 = nums[start] * nums[start];
            // maximum negative
            int prodt2 = nums[end] * nums[end];
            // maxium positive
            if (prodt2 > prodt1)
            {
                result[indx] = prodt2;
                indx--;
                end--;
            }
            else
            {
                result[indx] = prodt1;
                indx--;
                start++;
            }
        }
        return result;
    }
};