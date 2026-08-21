#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i ++ )
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> op, node;
    vector<int> col(n + 1, 1);
    int tmpmx = 0;
    auto dfs = [&](auto self, int fa, int sn) -> void{
        if(tmpmx % 2 == 0)
            col[sn] = 2;
        for(auto u : g[sn])
        {
            if(u == fa) continue;
            tmpmx ++;
            self(self, sn, u);
            tmpmx --;
        }
    };
    dfs(dfs, 0, 1);
    vector<int> tag(n + 1);
    // for(auto u : path)
    // {
    //     cout << u << ' ';
    // }
    // cout << endl;
    // cout << mx << endl;
    int cnt2 = n;
    auto dfs2 = [&](auto self, int fa, int sn) -> void{
        if(tag[sn] == 1 || cnt2 <= 2) return;
        for(auto u : g[sn])
        {
            if(sn == n) continue;
            if(u == fa)
            {
                if(col[sn] == col[n])
                {
                    tag[sn] = 1;
                    op.push_back(1);
                    op.push_back(2);
                    node.push_back(sn);
                    cnt2 --;
                }
                else
                {
                    tag[sn] = 1;
                    op.push_back(1);
                    op.push_back(1);
                    op.push_back(2);
                    node.push_back(sn);
                    cnt2 --;
                }
                continue;
            }
            self(self, sn, u);
        }
    };
    dfs2(dfs2, 0, 1);
    int cnt = 0;
    for(auto u : op)
    {

    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
}