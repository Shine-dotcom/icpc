#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    vector<string> a(n + 1);
    dp[1][1] = 1;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            if(a[i][j - 1] == 'R' || a[i][j - 1] == 'B')
            {
                dp[i][j] = (dp[i][j - 1] + dp[i][j]) % mod;
            }
            if(a[i - 1][j] == 'D' || a[i - 1][j] == 'B')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[n][m] << endl;
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