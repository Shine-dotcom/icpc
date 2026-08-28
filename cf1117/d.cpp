#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int s, q;
    cin >> s >> q;
    vector<int> fac(1);
    for(int i = 1; i * i <= s; i ++ )
    {
        if(s % i == 0)
        {
            fac.push_back(s / i);
            fac.push_back(i);
        }
    }
    sort(fac.begin() + 1, fac.end());
    int n = fac.size() - 1;
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i ++ )
    {
        pre[i] = pre[i - 1] + (fac[i] - fac[i - 1]) * (s / fac[i]);
    }
    while(q -- )
    {
        int x, y;
        cin >> x >> y;
        int i = upper_bound(fac.begin() + 1, fac.end(), x) - fac.begin() - 1;
        int j = upper_bound(fac.begin() + 1, fac.end(), y) - fac.begin() - 1;
        // cout << 111 << ' ' << n << ' ' << j << endl;
        int ans = 0;
        j = n - j;
        // cout << i << ' ' << j << endl;
        if(j < i) ans += pre[i] - pre[j];
        // cout << 222 << ' ' << ans << endl;
        if(i != n && x > fac[j]) ans += (x - fac[i]) * (s / fac[i + 1]);
        // cout << 333 << ' ' << ans << endl;
        ans += y * min(fac[j], x);
        // cout << 555 << ' ' << y << ' ' << fac[j] << endl;
        // cout << 444 << ' ' << ans << endl;
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}