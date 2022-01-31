//https://leetcode.com/problems/next-greater-element-i/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        vector<int> result;
        unordered_map<int, int> mp;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (st.size() > 0 && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(result.begin(), result.end());
        for (int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = result[i];
        }
        result.clear();
        for (int i = 0; i < nums1.size(); i++)
        {
            result.push_back(mp[nums1[i]]);
        }
        return result;
    }
};

//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/

class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here
        stack<long long> st;
        vector<long long> result;
        for (long long i = n - 1; i >= 0; i--)
        {
            while (st.size() > 0 && st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};