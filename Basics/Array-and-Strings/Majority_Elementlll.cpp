//https://www.codingninjas.com/codestudio/problems/elements-occur-more-than-n-k-times_1113146?leftPanelTab=0

// Modification of moore voting algorithim  also know as majority element general
// there is no benefit of making k-1 val and count so it better to use hashmap
vector<int> countTheNumber(vector<int> &arr, int n, int k)
{
    // Write your code here.
    unordered_map<int, int> m;
    for (auto it : arr)
    {
        m[it]++;
    }
    vector<int> result;
    for (auto it : m)
    {
        if (it.second >= n / k)
        {
            result.push_back(it.first);
        }
    }
    return result;
}
