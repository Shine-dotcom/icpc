#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> c[i];
    }
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    vector<int> flag(n + 1), cnt(n + 1, 1);
    auto dfs = [&](auto self, int fa, int sn)
    {
        if(flag[sn])
        {
            return;
        }
        if(c[fa] == c[sn]) cnt[sn] = cnt[fa] + 1;
        ans += cnt[sn] - 1;
        // cout << fa << ' ' << sn << endl;
        // cout << "cnt: " << cnt[fa] << ' ' << cnt[sn] << endl;
        for(auto x : g[sn])
        {
            flag[sn] = 1;
            self(self, sn, x);
            flag[sn] = 0;
        }
    };
    dfs(dfs, 0, 1);
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