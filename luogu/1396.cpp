#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node {
    int v, w;
    bool operator > (const node &u) const {
        return w > u.w;
    }
};
void solve()
{
    int n, m, st, ed;
    cin >> n >> m >> st >> ed;
    vector<vector<node>> g(n + 1);
    for(int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> dist(n + 1, 1e18);
    dist[st] = 0;
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({st, dist[st]});
    while(pq.size())
    {
        node a = pq.top();
        pq.pop();
        for(auto x : g[a.v])
        {
            if(dist[x.v] > max(dist[a.v], x.w))
            {
                dist[x.v] = max(dist[a.v], x.w);
                pq.push({x.v, dist[x.v]});
                // cout << x.v << ' ' << dist[x.v] << endl;
            }
        }
    }
    cout << dist[ed] << endl;
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