// https://leetcode.com/problems/majority-element-ii/
// https://www.codingninjas.com/codestudio/problems/893027?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int count1 = 0;
        int ele1 = 1e9 + 7;
        int count2 = 0;
        int ele2 = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
            {
                count1++;
            }
            else if (nums[i] == ele2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                ele1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                ele2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
                count1++;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele2)
                count2++;
        }
        if (count1 > n / 3)
        {
            result.push_back(ele1);
        }
        if (count2 > n / 3)
        {
            result.push_back(ele2);
        }
        return result;
    }
};