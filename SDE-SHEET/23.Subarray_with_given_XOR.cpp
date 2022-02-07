// https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &arr, int x)
{
    unordered_map<int, int> m;
    int xsum = 0;
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        xsum ^= arr[i];
        if (xsum == x)
        {
            count++;
        }
        if (m.find(xsum ^ x) != m.end())
        {
            count += m[xsum ^ x];
        }
        m[xsum]++;
    }
    return count;
}
