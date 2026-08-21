#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) cin >> b[i];
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i ++ )
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> l(n + 1), r(n + 1), son(n + 1), sz(n + 1, 1), ca(n + 1), cb(n + 1), rnk(n + 1);
    int tot = 0;
    int timer = 0;
    auto dfs1 = [&](auto self, int fa, int sn) -> void {
        l[sn] = ++ timer;
        rnk[timer] = sn;
        int tmp = 0;
        for(auto u : g[sn])
        {
            if(u == fa) continue;
            self(self, sn, u);
            sz[sn] += sz[u];
            if(tmp < sz[u])
            {
                tmp = sz[u];
                son[sn] = u;
            }
        }
        r[sn] = timer;
    };
    vector<int> ans(n + 1);
    auto add = [&](int u) -> void {
        // if(a[u] == 0 || ca[a[u]] < cb[a[u]]) tot ++;
        // ca[a[u]] ++;
        // if(b[u] == 0 || cb[b[u]] < ca[b[u]]) tot ++;
        // cb[b[u]] ++;
        /*
            具体逻辑
        */
    };
    auto del = [&](int u) -> void {
        // if(a[u] == 0 || ca[a[u]] <= cb[a[u]]) tot --;
        // ca[a[u]] --;
        // if(b[u] == 0 || cb[b[u]] <= ca[b[u]]) tot --;
        // cb[b[u]] --;
        /*
            具体逻辑
        */
    };
    auto dfs2 = [&](auto self, int fa, int sn, bool keep) -> void {
        for(auto u : g[sn])
        {
            if(son[sn] == u || u == fa) continue;
            self(self, sn, u, 0);
        }
        if(son[sn]) self(self, sn, son[sn], 1);
        for(auto u : g[sn])
        {
            if(u == fa || u == son[sn]) continue;
            for(int i = l[u]; i <= r[u]; i ++ )
            {
                add(rnk[i]);
            }
        }
        add(sn);
        ans[sn] = tot;
        if(!keep)
            for(int i = l[sn]; i <= r[sn]; i ++ ) del(rnk[i]);
    };
    dfs1(dfs1, 0, 1);
    dfs2(dfs2, 0, 1, 0);
    for(int i = 1; i <= n; i ++ )
    {
        // cout << i << ' ' << ans[i] << ' ' << sz[i] << endl;
        if(ans[i] >= sz[i]) cout << 1;
        else cout << 0;
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