#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i ++ )
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> order;
    vector<int> flag(n + 1), in(n + 1), out(n + 1);
    int timer = 0;
    auto dfs = [&](auto self, int x) -> void {
        if(flag[x]) return;
        flag[x] = 1;
        in[x] = ++ timer;
        order.push_back(x);
        for(auto v : g[x])
        {
            self(self, v);
        }
        out[x] = timer;
    };
    dfs(dfs, 1);
    for(auto x : order) cout << x << ' ';
    cout << endl;
    for(int i = 1; i <= n; i ++ )
    {
        cout << i << ' ' << in[i] << ' ' << out[i] << endl;
    }
    cout << endl;
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