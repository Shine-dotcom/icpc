#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> c(n + 1);
    bool flag = 0;
    vector<int> f(n + 1);
    auto dfs = [&](auto self, int fa, int sn) -> void {
        if(c[fa] == c[sn])
        {
            flag = 1;
        }
        if(c[sn]) return;
        for(auto u : g[sn])
        {
            if(c[u] == 0)
            {
                cout << u << ' ' << sn << endl;
                c[u] = 3 - c[sn];
                self(self, sn, u);
            }
        }
    };
    for(int i = 1; i <= n; i ++ )
    {
        if(c[i] == 0)
        {
            c[i] = 1;
            dfs(dfs, 0, i);
        }
    }
    for(int i = 1; i <= n; i ++ ) cout << c[i] << ' ';
    cout << endl;
    cout << (flag ? "No" : "Yes") << endl;
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