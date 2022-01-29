//https://leetcode.com/problems/next-greater-element-iii/

// how to implememt next-permuation in O(N) time
// 2 approach explains that

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        vector<int> arr;
        int duplicate = n;
        while (duplicate > 0)
        {
            arr.push_back(duplicate % 10);
            duplicate = duplicate / 10;
        }
        reverse(arr.begin(), arr.end());
        next_permutation(arr.begin(), arr.end());
        int ten = arr.size() - 1;
        long long int val = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            val = val + (arr[i] * pow(10, ten));
            ten--;
        }
        if (val > n && val <= 2147483647)
        {
            return val;
        }
        else
        {
            return -1;
        }
    }
};

//best approach
class Solution
{
public:
    // implementation of next_permutation function
    int permutation(vector<int> &arr, int n)
    {
        int j = n - 2;
        while (j >= 0)
        {
            if (arr[j] < arr[j + 1])
            {
                break;
            }
            j--;
        }
        vector<int> res;
        if (j == -1)
        {
            return 0;
        }
        else
        {
            int i = n - 1;
            for (i = n - 1; i >= 0; i--)
            {
                if (arr[i] > arr[j])
                {
                    break;
                }
            }
            swap(arr[i], arr[j]);
            reverse(arr.begin() + j + 1, arr.end());
        }
        return 1;
    }

    // orginal question
    int nextGreaterElement(int n)
    {
        vector<int> arr;
        int duplicate = n;
        while (duplicate > 0)
        {
            arr.push_back(duplicate % 10);
            duplicate = duplicate / 10;
        }
        reverse(arr.begin(), arr.end());
        int res = permutation(arr, arr.size());
        if (res == 0)
        {
            return -1;
        }
        int ten = arr.size() - 1;
        long long int val = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            val = val + (arr[i] * pow(10, ten));
            ten--;
        }
        if (val > n && val <= 2147483647)
        {
            return val;
        }
        else
        {
            return -1;
        }
    }
};