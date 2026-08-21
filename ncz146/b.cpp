#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i].first >> a[i].second;
    }
    int ans = k;
    for(int i = 1; i <= n; i ++ )
    {
        ans = min(ans, abs(a[i].first) + abs(k - a[i].second));
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}