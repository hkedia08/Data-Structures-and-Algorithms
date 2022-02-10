#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(m);
        ll sum1 = 0, sum2 = 0;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < m; i++)
            cin >> b[i];
        sum1 = accumulate(a.begin(), a.end(), sum1);
        sum2 = accumulate(b.begin(), b.end(), sum2);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<ll>());
        ll count = 0;
        if (sum1 > sum2)
            cout << 0 << endl;
        else
        {
            for (ll i = 0; i < min(n, m); i++)
            {
                if (sum1 > sum2)
                    break;
                count++;
                sum1 -= a[i];
                sum1 += b[i];
                sum2 -= b[i];
                sum2 += a[i];
                swap(a[i], b[i]);
            }
            if (sum1 <= sum2)
                cout << -1 << endl;
            else
                cout << count << endl;
        }
    }
}