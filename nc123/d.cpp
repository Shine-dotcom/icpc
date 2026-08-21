#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int v, w;
    bool operator < (const node &u) const{
        return w < u.w;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<node>> g(n + 1);
    vector<int> dist(n + 1, 1e18);
    for(int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        // cout << u << v << w << endl;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i ++ )
    {
        int mn = 1e9;
        for(auto [v, w] : g[i])
        {
            mn = min(mn, w);
        }
        for(auto &[v, w] : g[i])
        {
            w = min(2 * mn, w);
        }
    }
    priority_queue<node> pq;
    dist[1] = 0;
    pq.push({1, 0});
    while(pq.size())
    {
        auto u = pq.top();
        pq.pop();
        for(auto [v, w] : g[u.v])
        {
            if(dist[u.v] + w < dist[v])
            {
                dist[v] = dist[u.v] + w;
                pq.push({v, w});
            }
        }
    }
    cout << (dist[n] == 1e18 ? -1 : dist[n]) << endl;
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