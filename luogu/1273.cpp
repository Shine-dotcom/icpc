#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int p, v;
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> c(n + 1);
    for(int i = 1; i <= n - m; i ++ )
    {
        int k;
        cin >> k;
        while(k -- )
        {
            int a, cost;
            cin >> a >> cost;
            c[a] = -cost;
            g[i].push_back(a);
        }
    }
    for(int i = n - m + 1; i <= n; i ++ )
    {
        int money;
        cin >> money;
        c[i] += money;
    }
    vector<int> sz(n + 1, 1), f(n + 1);
    int cnt = 0;
    auto dfs = [&](auto self, int fa, int sn) -> void{
        for(auto u : g[sn])
        {
            self(self, sn, u);
            sz[sn] += sz[u];
        }
        f[++ cnt] = sn;
    };
    dfs(dfs, 0, 1);
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1e18));
    for(int i = 0; i <= n; i ++ )
    {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= cnt; i ++ )
    {
        int u = f[i];
        for(int j = 1; j <= m; j ++ )
        {
            if(n - m + 1 <= u) dp[i][j] = max(dp[i - 1][j - 1] + c[u], dp[i - 1][j]);
            else dp[i][j] = max(dp[i - 1][j] + c[u], dp[i - sz[u]][j]);
        }
    }
    for(int j = m; j >= 0; j -- )
    {
        if(dp[cnt][j] >= 0)
        {
            cout << j << endl;
            return;
        }
    }
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
}