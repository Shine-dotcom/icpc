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
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> depth(n + 1);
    vector<int> flag(n + 1);
    bool ans = 0;
    auto dfs = [&](auto self, int dep, int fa, int sn) -> void {
        if(flag[sn])
        {
            // cout << "dep: " << dep << endl;
            if(g[fa].size() == 1)
            {
                depth[dep] ++;
            }
            return;
        }
        for(auto x : g[sn])
        {
            flag[sn] = 1;
            self(self, dep + 1, sn, x);
        }
    };
    dfs(dfs, 0, 0, 1);
    for(int i = 1; i <= n; i ++ )
    {
        if(depth[i] >= i)
        {
            cout << "red" << endl;
            return;
        }
    }
    cout << "purple" << endl;
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