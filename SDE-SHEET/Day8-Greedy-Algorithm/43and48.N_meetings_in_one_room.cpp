// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

it is safe to use pair instead of 2d vector class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), cmp);
        int freeTime = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (freeTime < v[i].first)
            {
                ans++;
                freeTime = v[i].second;
            }
        }
        return ans;
    }
};
