#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1), dp(n + 1, vector<int> (2, 1e9));
    for(int i = 1; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto dfs = [&](auto self, int fa, int sn) -> void{
        dp[sn][0] = 0;
        dp[sn][1] = 1;
        for(auto x : g[sn])
        {
            if(x == fa) continue;

            self(self, sn, x);

            dp[sn][0] += dp[x][1];
            dp[sn][1] += min(dp[x][0], dp[x][1]);
        }
    };
    dfs(dfs, 0, 1);
    for(int i = 1; i <= n; i ++ )
    {
        cout << min(dp[i][0], dp[i][1]) << " \n"[i == n];
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
}