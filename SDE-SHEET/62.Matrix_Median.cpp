// https://www.interviewbit.com/problems/matrix-median/#

int findsmallerequal(vector<int> &row, int mid)
{
    int low = 0;
    int high = row.size() - 1;
    while (low <= high)
    {
        int m = (low + high) / 2;
        if (row[m] <= mid)
            low = m + 1;
        else
            high = m - 1;
    }
    return low;
}

int Solution::findMedian(vector<vector<int>> &A)
{
    int low = 0;
    int high = 1e9;
    int mid;
    int n = A.size();
    int m = A[0].size();
    while (low <= high)
    {
        mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += findsmallerequal(A[i], mid);
        }
        if (cnt <= ((n * m) / 2))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}