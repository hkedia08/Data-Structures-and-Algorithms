//https://www.interviewbit.com/problems/nearest-smaller-element/
void ngt(vector<int> &nums,vector<int>&result)
    {
        int n = nums.size();
        stack<int> s;
        for (int i = 0; i<n; i++)
        {
        while (!s.empty() && s.top()>=nums[i]){
                s.pop();
        }
            if (s.size() == 0)
            {
               result[i] = -1;
                // s.push(nums[i]);
            }
            else
                result[i] = s.top();
                 s.push(nums[i]);
        }
    }

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int>result(A.size(),-1);
      ngt(A,result);
    return result;
}
