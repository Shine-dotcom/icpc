#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct edge {
    int u, v, w;
    bool operator < (const edge &e) const {
        return w < e.w;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<edge> e(m + 1);
    for(int i = 1; i <= m; i ++ )
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e.begin() + 1, e.end());
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
    for(int i = 1; i <= m; i ++ )
    {
        if(find(find, e[i].v) != find(find, e[i].u))
        {
            merge(e[i].v, e[i].u);
            ans = max(ans, e[i].w);
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