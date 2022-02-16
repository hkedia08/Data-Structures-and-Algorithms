// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution
{
public:
    static bool cmp(pair<double, double> &a, pair<double, double> &b)
    {
        double partA = (a.first / b.first);
        double partB = (a.second / b.second);
        if (partB < partA)
            return false;
        else
            return true;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        vector<pair<double, double>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i].value, arr[i].weight});
        }
        sort(v.begin(), v.end(), cmp);
        double ans = 0.0;
        for (int i = n - 1; i >= 0; i--)
        {
            // cout<<v[i][0]<<" "<<v[i][1]<<endl;
            double val = double(double(v[i].first) / double(v[i].second));
            if (w >= v[i].second)
            {
                ans += double(v[i].first);
                w = w - v[i].second;
            }
            else
            {
                ans += double(double(val) * double(w));
                w = max(0.0, double(w) - v[i].second);
            }
            //   cout<<ans<<endl;
            if (w == 0)
                break;
        }
        return ans;
    }
};