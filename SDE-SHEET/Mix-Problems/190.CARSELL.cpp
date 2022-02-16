// https://www.codechef.com/problems/CARSELL

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    long long mod = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            long long val;
            cin >> val;
            v.push_back(val);
        }
        sort(v.begin(), v.end(), greater<long long>());
        long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            if (v[i] >= i)
                v[i] -= i;
            else
                v[i] = 0;
            ans = (ans % mod + v[i] % mod) % mod;
        }
        cout << ans << endl;
    }
}