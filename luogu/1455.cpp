#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n, m, w;
    cin >> n >> m >> w;
    vector<int> c(n + 1), d(n + 1);
    vector<int> mp_c(n + 1), mp_d(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> c[i] >> d[i];
    }
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        f[i] = i;
    }
    auto find = [&](auto self, int x) -> int{
        return (f[x] == x ? x : f[x] = self(self, f[x]));
    };
    auto merge = [&](int x, int y) -> void{
        if(find(find, x) != find(find, y))
        {
            f[find(find, x)] = find(find, y);
        }
    };
    for(int i = 1; i <= m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for(int i = 1; i <= n; i ++ )
    {
        mp_c[find(find, i)] += c[i];
        mp_d[find(find, i)] += d[i];
    }
    vector<int> dp(w + 1);
    for(int i = 1; i <= n; i ++ )
    {
        if(mp_d[i])
        {
            for(int j = w; j >= mp_c[i]; j -- )
            {
                dp[j] = max(dp[j], dp[j - mp_c[i]] + mp_d[i]);
            }
        }
    }
    cout << dp[w] << endl;
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