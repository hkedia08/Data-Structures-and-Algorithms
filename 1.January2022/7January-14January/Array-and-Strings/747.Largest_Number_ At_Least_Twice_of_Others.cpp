//https://leetcode.com/problems/largest-number-at-least-twice-of-others/

// always think for edge cases when n==0 and n==1
// think brute force then try to optimize it

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        else
        {
            // finding the largest element and its index
            int largest = INT_MIN;
            int index = -1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > largest)
                {
                    largest = nums[i];
                    index = i;
                }
            }
            // check for whether all the elements value *2 is less than largest or not
            int ans = -1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (i != index)
                {
                    if (nums[i] * 2 <= largest)
                    {
                        ans = index;
                        continue;
                    }
                    else
                    {
                        ans = -1;
                        break;
                        ;
                    }
                }
            }
            return ans;
        }
    }
};
