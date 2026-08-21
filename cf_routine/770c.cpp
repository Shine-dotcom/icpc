#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g1(n + 1), g2(n + 1);
    vector<int> deg(n + 1), flag(n + 1), tar(k + 1);
    for(int i = 1; i <= k; i ++ )
    {
        cin >> tar[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        int m;
        cin >> m;
        for(int j = 1; j <= m; j ++ )
        {
            int x;
            cin >> x;
            g1[x].push_back(i);
            g2[i].push_back(x);
        }
        deg[i] = m;
    }
    // for(auto x : deg)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    queue<int> q;
    for(int i = 1; i <= n; i ++ )
    {
        if(deg[i] == 0) q.push(i);
    }
    vector<int> res;
    set<int> st;
    while(q.size())
    {
        int t = q.front();
        // cout << t << endl;
        res.push_back(t);
        st.insert(t);
        q.pop();
        for(auto x : g1[t])
        {
            deg[x] --;
            if(deg[x] == 0) q.push(x);
        }
    }
    // for(auto x : res)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    int f = 0;
    auto dfs = [&](auto self, int fa, int sn, int dep) -> void {
        if(flag[sn]) return;
        if(dep > n + 1)
        {
            f = 1;
            return;
        }
        flag[sn] = 1;
        // cout << "sn: " << sn << endl;
        for(auto x : g2[sn])
        {
            // cout << sn << ' ' << x << endl;
            self(self, sn, x, dep + 1);
        }
    };
    for(int i = 1; i <= k; i ++ )
    {
        dfs(dfs, 0, tar[i], 0);
    }
    if(f)
    {
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= n; i ++ )
    {
        if(flag[i] && st.find(i) == st.end())
        {
            cout << -1 << endl;
            return;
        }
    }
    int cnt = 0;
    for(auto x : res)
    {
        if(flag[x])
        {
            cnt ++;
            // cout << x << ' ';
        }
    }
    cout << cnt << endl;
    for(auto x : res)
    {
        if(flag[x])
        {
            cout << x << ' ';
        }
    }
    cout << endl;
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