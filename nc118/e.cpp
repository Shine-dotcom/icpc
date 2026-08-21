#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    int a, b;
    cin >> a >> b;
    for(int i = 1; i < n; i ++ )
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // for(int i = 1; i <= n; i ++ )
    // {
    //     for(auto u : g[i])
    //     cout << u << ' ';
    //     cout << endl;
    // }
    vector<int> da(n + 1), db(n + 1);
    auto dfs = [&](auto self, int fa, int sn, int dep, vector<int> &d) -> void{
        d[sn] = dep;
        // cout << fa << ' ' << g[fa].size() << endl;
        for(auto u : g[sn])
        {
            if(u == fa) continue;
            self(self, sn, u, dep + 1, d);
        }
    };
    dfs(dfs, 0, a, 0, da);
    dfs(dfs, 0, b, 0, db);
    // cout << p << ' ' << leaf << endl;
    int flag = 0;
    for(int i = 1; i <= n; i ++ )
    {
        // cout << da[i] << ' ' << db[i] << endl;
        if(g[i].size() == 1)
        {
            if(da[i] * 2 <= db[i])
            {
                flag = 1;
                break;
            }
        }
    }
    cout << (flag ? "red" : "purple") << endl;
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
