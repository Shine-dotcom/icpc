#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> dfn(n + 1), low(n + 1, 1e18), a(n + 1), in(n + 1);
    vector<vector<int>> g(n + 1), gn(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int tim = 0;
    stack<int> stk;
    vector<int> belong(n + 1);
    auto dfs1 = [&](auto self, int fa, int sn) -> void {
        low[sn] = dfn[sn] = ++ tim;
        belong[sn] = sn;
        stk.push(sn);
        for(auto u : sn)
        {
            if(dfn[u] == 0)
            {
                dfs1(sn, u);
                low[sn] = min(low[sn], low[u]);
                a[sn] += a[u];
            }
            else low[sn] = min(low[sn], dfn[u]);
            a[sn] += a[u];
            if(low[u] == dfn[u])
            {
                while(stk.top() != u)
                {
                    a[u] += a[stk.top()];
                    a[stk.top()] = 0;
                    belong[stk.top()] = u;
                    stk.pop();
                }
            }
        }
    };
    dfs1(dfs1, 0, 1);
    
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