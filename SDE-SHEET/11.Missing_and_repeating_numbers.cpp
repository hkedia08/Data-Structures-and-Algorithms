// https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

// solution-> https://youtu.be/MvklwzVz654
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int xxory = 0;
    for (int i = 0; i < n; i++)
        xxory ^= arr[i];
    for (int i = 1; i <= n; i++)
        xxory ^= i;
    int rsb = xxory & -xxory;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & rsb) == 0)
            x ^= arr[i];
        else
            y ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i & rsb) == 0)
            x ^= i;
        else
            y ^= i;
    }
    int repeat, missing;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            repeat = x;
            missing = y;
            break;
        }
        else if (arr[i] == y)
        {
            repeat = y;
            missing = x;
            break;
        }
    }
    pair<int, int> result = {missing, repeat};
    return result;
}
