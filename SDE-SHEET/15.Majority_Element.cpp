// https://leetcode.com/problems/majority-element/
// https://www.codingninjas.com/codestudio/problems/842495?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int ele;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                ele = nums[i];
            }
            if (nums[i] == ele)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return ele;
    }
};