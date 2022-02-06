// https://leetcode.com/problems/reverse-pairs/

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int i, j, k;
        int count = 0;
        i = low, j = mid + 1;
        int right = mid + 1;
        // this is the condition check
        for (int left = low; left <= mid; left++)
        {
            while (right <= high && arr[left] > 2LL * arr[right])
            {
                right++;
            }
            count += (right - (mid + 1));
        }
        // end here
        vector<int> temp;
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
            }
        }
        while (i <= mid)
        {
            temp.push_back(arr[i++]);
        }
        while (j <= high)
        {
            temp.push_back(arr[j++]);
        }
        for (int s = low; s <= high; s++)
            arr[s] = temp[s - low];
        return count;
    }
    int inversioncount(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;
        int inv = inversioncount(arr, low, mid);
        inv += inversioncount(arr, mid + 1, high);
        inv += merge(arr, low, mid, high);
        return inv;
    }
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        return inversioncount(nums, 0, n - 1);
    }
};