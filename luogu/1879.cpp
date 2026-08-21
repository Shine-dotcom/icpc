#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 15, M = 4200, mod = 1e8;
int dp[N][M];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int t = m, bit;
        for(int j = 1; j <= m; j ++ )
        {
            cin >> bit;
            a[i] += (bit << (-- t));
        }
        // cout << a[i] << endl;
    }
    for(int i = 0; i < (1 << m); i ++ )
    {
        if((a[1] | i) != a[1]) continue;
        if((i & (i << 1)) != 0) continue;
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i ++ )
    {
        for(int j = 0; j < (1 << m); j ++ )
        {
            if((a[i] | j) != a[i]) continue;
            if((j & (j << 1)) != 0) continue;
            for(int k = 0; k < (1 << m); k ++ )
            {
                if(j & k) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }
    }
    int ans = 0;
    // for(int i = 1; i <= n; i ++ )
    // {
    //     for(int j = 0; j < (1 << m); j ++ ) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << endl;
    for(int i = 0; i < (1 << m); i ++ )
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << endl;
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