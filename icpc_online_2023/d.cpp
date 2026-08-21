#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct lian {
    int ver, edge;
    bool operator < (const lian &u) const {
        return ver < u.ver;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> flag(n + 1);
    queue<int> q;
    vector<lian> a;
    auto bfs = [&](int st) -> void {
        if(flag[st]) return;
        int ver = 1, edge = 0;
        q.push(st);
        flag[st] = 1;
        while(q.size())
        {
            int fr = q.front();
            q.pop();
            for(auto x : g[fr])
            {
                edge ++;
                if(flag[x]) continue;
                ver ++;
                flag[x] = 1;
                q.push(x);
            }
        }
        a.push_back({ver, edge / 2});
    };
    for(int i = 1; i <= n; i ++ ) bfs(i);
    // for(auto x : a)
    // {
    //     cout << x.ver << ' ' << x.edge << endl;
    // }
    sort(a.begin(), a.end());
    int ans = 0;
    for(auto [v, e] : a)
    {
        if(e < v * (v - 1) / 2)
        {
            ans += v * (v - 1) / 2 - e;
        }
    }
    if(!ans)
    {
        ans = a[0].ver * a[1].ver;
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