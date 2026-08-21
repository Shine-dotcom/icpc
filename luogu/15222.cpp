#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int u, w, v;
};
void solve()
{
    int b, n;
    cin >> b >> n;
    map<string, int> mp;
    vector<vector<node>> g(10010);
    vector<int> w(10010, 1e18), v(10010), inn(10010);
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
        string s0, s1, s2;
        int w, v;
        cin >> s0 >> s1 >> s2 >> w >> v;
        if(!mp[s1]) mp[s1] = ++ cnt;
        if(!mp[s0]) mp[s0] = ++ cnt;
        g[mp[s1]].push_back({mp[s0], w, v});
        inn[mp[s0]] ++;
    }
    queue<int> q;
    for(int i = 1; i <= cnt; i ++ )
    {
        if(inn[i] == 0)
        {
            q.push(i);
            w[i] = 0;
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto x : g[u])
        {
            inn[x.u] --;
            if(w[x.u] > x.w + w[u])
            {
                w[x.u] = x.w + w[u];
                v[x.u] = x.v + v[u];
            }
            else if(w[x.u] == x.w + w[u])
            {
                v[x.u] = max(v[x.u], x.v + v[u]);
            }
            if(inn[x.u] == 0)
            {
                q.push(x.u);
            }
        }
    }
    vector<int> dp(b + 1);
    for(int i = 1; i <= cnt; i ++ )
    {
        for(int j = b; j >= w[i]; j -- )
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[b] << endl;
    for(int i = 0; i <= b; i ++ )
    {
        if(dp[i] == dp[b])
        {
            cout << i << endl;
            return;
        }
    }
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