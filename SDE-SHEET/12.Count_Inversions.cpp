// https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/

#define mod 1000000007
long long temp[10000007] = {0};
long long merge(long long *arr, long low, long long high)
{
    long long i, j, k;
    long long count = 0;
    long long mid = (low + high) / 2;
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += (mid - i) + 1;
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    for (int s = low; s <= high; s++)
        arr[s] = temp[s];
    return count;
}
long long inversioncount(long long *arr, long long low, long long high)
{
    if (low >= high)
        return 0;
    long long mid = (low + high) / 2;
    long long count1 = inversioncount(arr, low, mid);
    long long count2 = inversioncount(arr, mid + 1, high);
    long long count3 = merge(arr, low, high);
    return count1 + count2 + count3;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return inversioncount(arr, 0, n - 1);
}

// while merging we had to count inversions it is complete code of merge sort