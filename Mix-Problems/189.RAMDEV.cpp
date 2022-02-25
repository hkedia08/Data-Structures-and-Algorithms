// https://www.codechef.com/problems/RAMDEV

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    long long l, b, n, L, B;
    cin >> l >> b >> n;
    long long result1, result2;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> L >> B;
        if (L >= l and B >= b)
            result1 = (L / l) * (B / b);
        else
            result1 = 0;
        if (B >= l and L >= b)
            result2 = (B / l) * (L / b);
        else
            result2 = 0;
        ans += max(result1, result2);
    }
    cout << ans << endl;
}