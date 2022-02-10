// https://www.codechef.com/problems/SAVKONO
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, z;
        cin >> n >> z;
        priority_queue<ll> p;
        for (ll i = 0; i < n; i++)
        {
            ll in;
            cin >> in;
            p.push(in);
        }
        ll ans = 0;
        while (!p.empty() && z > 0)
        {
            ans++;
            ll val = p.top();
            p.pop();
            z -= val;
            val = val / 2;
            if (val > 0)
                p.push(val);
        }
        if (z <= 0)
            cout << ans << endl;
        else
            cout << "Evacuate" << endl;
    }
}