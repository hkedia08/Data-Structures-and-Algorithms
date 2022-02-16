// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#

class Solution
{
public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if (n > m)
            return kthElement(nums2, nums1, m, n, k);
        // if k is greater than m then we had to choose atleast k-m elements from first array
        int low = max(0, k - m);
        // if k is less than n then we had to do binary search in k space only
        int high = min(k, n);
        while (low <= high)
        {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            int right1 = cut1 == n ? INT_MAX : nums1[cut1];
            int right2 = cut2 == m ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1)
            {
                return max(left1, left2);
            }
            else if (left1 > right2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 0;
    }
};