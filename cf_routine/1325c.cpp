#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node {
    int u, idx;
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<node>> g(n + 1);
    for(int i = 1; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    int cnt = 3;
    vector<int> v(n, -1);
    vector<int> flag(n + 1, 0);
    int f = 0;
    int ver = 1;
    for(int i = 1; i <= n; i ++ )
    {
        if(g[i].size() >= 3)
        {
            ver = i;
            break;
        }
    }
    auto dfs = [&](auto self, int fa, int sn) -> void {
        if(flag[sn])
            return;
        flag[sn] = 1;
        if(g[sn].size() >= 3 && f == 0)
        {
            if(v[g[sn][0].idx] == -1)
                v[g[sn][0].idx] = 0;
            if(v[g[sn][1].idx] == -1)
                v[g[sn][1].idx] = 1;
            if(v[g[sn][2].idx] == -1)
                v[g[sn][2].idx] = 2;
            f = 1;
        }
        for(auto u : g[sn])
        {
            if(v[u.idx] == -1)
            {
                v[u.idx] = cnt ++;
            }
            self(self, sn, u.u);
        }
    };
    dfs(dfs, 0, ver);
    for(int i = 1; i < n; i ++ )
    {
        cout << (f ? v[i] : v[i] - 3) << endl;
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