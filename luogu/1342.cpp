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
    int n, m;
    cin >> n >> m;
    vector<vector<node>> g1(n + 1), g2(n + 1);
    for(int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        g1[u].push_back({v, w});
        g2[v].push_back({u, w});
    }
    priority_queue<node, vector<node>, greater<node>> pq;
    vector<int> dist(n + 1, 1e18);
    dist[1] = 0;
    int ans = 0;
    pq.push({1, dist[1]});
    while(pq.size())
    {
        auto t = pq.top();
        pq.pop();
        for(auto x : g1[t.v])
        {
            if(dist[x.v] > dist[t.v] + x.w)
            {
                dist[x.v] = dist[t.v] + x.w;
                pq.push({x.v, dist[x.v]});
            }
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        ans += dist[i];
    }
    for(int i = 1; i <= n; i ++ ) dist[i] = 1e18;
    dist[1] = 0;
    pq.push({1, dist[1]});
    while(pq.size())
    {
        auto t = pq.top();
        pq.pop();
        for(auto x : g2[t.v])
        {
            if(dist[x.v] > dist[t.v] + x.w)
            {
                dist[x.v] = dist[t.v] + x.w;
                pq.push({x.v, dist[x.v]});
            }
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        ans += dist[i];
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- ) solve();
    return 0;
}