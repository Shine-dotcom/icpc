#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct edge {
    int u, v, w;
    bool operator > (const edge &e) const {
        return w > e.w;
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    for(int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({u, v, w});
    }
    if(n < k)
    {
        cout << "No Answer" << endl;
        return;
    }
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        f[i] = i;
    }
    auto find = [&](auto self, int i) -> int {
        return (f[i] == i ? i : f[i] = self(self, f[i]));
    };
    auto merge = [&](int x, int y) -> void {
        int u = find(find, x);
        int v = find(find, y);
        if(u != v) f[u] = v;
    };
    int cnt = 0;
    int ans = 0;
    while(pq.size())
    {
        if(cnt >= n - k) break;
        edge e = pq.top();
        pq.pop();
        if(find(find, e.u) != find(find, e.v))
        {
            merge(e.u, e.v);
            ans += e.w;
            cnt ++;
        }
    }
    if(cnt < n - k)
    {
        cout << "No Answer" << endl;
        return;
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