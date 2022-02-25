// https://leetcode.com/problems/search-a-2d-matrix/

// https://www.codingninjas.com/codestudio/problems/980531?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int low, high;
        low = 0;
        high = n * m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (matrix[mid / n][mid % n] == target)
            {
                return true;
            }
            if (matrix[mid / n][mid % n] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};