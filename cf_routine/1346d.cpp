#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node {
    int v, w;
};
struct edge {
    int u, v, w;
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<node>> g(n + 1);
    vector<edge> e(m + 1);
    for(int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> ans(n + 1, -1);
    for(int i = 1; i <= n; i ++ )
    {
        for(auto &[v, w] : g[i])
        {
            ans[i] = max(ans[i], w);
        }
    }
    // int flag = 1;
    for(int i = 1; i <= m; i ++ )
    {
        int tmp = min(ans[e[i].u], ans[e[i].v]);
        if(tmp != e[i].w)
        {
            cout << "NO" << endl;
            return;
        }
    }
    // if(!flag)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i ++ )
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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