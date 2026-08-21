#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1, 1e9);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    reverse(begin(a) + 1, end(a));
    // for(auto x : a)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    vector<int> cnt(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        pre[i] = min(pre[i - 1], a[i]);
        cnt[pre[i]] ++;
        ans += a[i] - pre[i];
    }
    int res = 0;
    for(int i = 1; i <= n; i ++ )
    {
        res = max(res, cnt[i] - 1);
    }
    cout << ans + res << endl;
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