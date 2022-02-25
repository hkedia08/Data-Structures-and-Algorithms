// https://leetcode.com/problems/merge-sorted-array/
// https://www.codingninjas.com/codestudio/problems/1214628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int s = m + n - 1;
        m--, n--;
        while (m >= 0 && n >= 0)
        {
            if (nums1[m] > nums2[n])
            {
                nums1[s] = nums1[m];
                m--;
            }
            else if (nums1[m] <= nums2[n])
            {
                nums1[s] = nums2[n];
                n--;
            }
            s--;
        }
        while (m >= 0)
        {
            nums1[s] = nums1[m];
            s--, m--;
        }
        while (n >= 0)
        {
            nums1[s] = nums2[n];
            s--, n--;
        }
    }
};