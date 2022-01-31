//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

// This problem is application of LIS

// steps to solve this problem
// 1. Sort the indivdual vector so that we got maximum height
// 2. Sort the complexte 3d vector so minimum l*b is at the top
// 3. Use LIS ( basically ans will be reverse of the order but we need only int so no need).
// 4. find the maximum element in whole dp arrray

// O(N^2) time complexity
class Solution
{
public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        // sort every vector so that height is maximum in everyone
        for (auto &c : cuboids)
        {
            sort(c.begin(), c.end());
        }
        // sorted so that we can use LIS
        sort(cuboids.begin(), cuboids.end());
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            // height of that cuboid
            dp[i] = cuboids[i][2];
            for (int j = 0; j <= i - 1; j++)
            {
                if ((cuboids[i][0] >= cuboids[j][0]) && (cuboids[i][1] >= cuboids[j][1]) && (cuboids[i][2] >= cuboids[j][2]))
                {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};

//https://practice.geeksforgeeks.org/problems/box-stacking/1
// This is small variation
// there will be 3 possible way for each vector so total of n*3 ways
// 1. It is also allowable to use multiple instances of the same type of box.
// sorting based on area we will use c++ compartor
// 2. Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area.

// 3. this condition in longest decreasing subsequence   l1>l2 and b1>b2

// rest everything is same
