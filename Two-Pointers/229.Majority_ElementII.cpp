// extension of moore voting algorithim

// intituion->n%3 then it have only 0,1,2 as a remainder
// so it can have at max 2 majority elements
// (n/3+1)+(n/3+1) then next must be <n/3

class Solution
{
public:
    bool checkformajority(vector<int> &nums, int val)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
                count++;
        }
        return count > nums.size() / 3;
    }

    vector<int> majorityElement(vector<int> &nums)
    {
        int val1 = INT_MAX;
        int val2 = INT_MAX;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val1)
                count1++;
            else if (nums[i] == val2)
                count2++;
            else
            {
                if (count1 == 0)
                {
                    val1 = nums[i];
                    count1++;
                }
                else if (count2 == 0)
                {
                    val2 = nums[i];
                    count2++;
                }
                else
                {
                    count1--;
                    count2--;
                }
            }
        }
        vector<int> result;
        if (checkformajority(nums, val1) == true)
        {
            result.push_back(val1);
        }
        if (checkformajority(nums, val2) == true)
        {
            result.push_back(val2);
        }
        return result;
    }
};
