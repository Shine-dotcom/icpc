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
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            cin >> g[i][j];
        }
    }
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j < i; j ++ )
        {
            pq.push({i, j, g[i][j]});
        }
    }
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        f[i] = i;
    }
    auto find = [&](auto self, int i) -> int {
        return (f[i] == i ? i : f[i] = self(self, f[i]));
    };
    auto merge = [&](int u, int v) -> void {
        int x = find(find, u);
        int y = find(find, v);
        if(x != y) f[x] = y;
    };
    int ans = 0;
    while(pq.size())
    {
        edge e = pq.top();
        pq.pop();
        if(find(find, e.u) != find(find, e.v))
        {
            merge(e.u, e.v);
            ans += e.w;
        }
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