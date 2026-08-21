#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> times(n + 1);
    for(auto u : a)
    {
        times[u] ++;
    }
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        p[i] = p[i - 1] + times[i];
    }
    int ans = 1;
    for(int g = 1; g <= n; g ++ )
    {
        int t = min(n, 4 * g - 1);
        int good = p[n] - p[t];
        good += times[g];
        if(2 * g <= n) good += times[2 * g];
        if(3 * g <= n) good += times[3 * g];
        if(good >= n - k) ans = max(ans, g);
    }
    cout << ans << endl;
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
}