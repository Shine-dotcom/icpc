#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> dp(n + 1, vector<int> (2));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= min(i, k); j ++ )
        {
            if(j < d)
                dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
            else
                dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
            dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
        }
    }
    cout << dp[n][1] << endl;
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