#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<vector<vector<int>>> dp(2, vector<vector<int>> (t + 1, vector<int> (n + 1)));
    dp[1][0][1] = 2;
    for(int i = 2; i <= n; i ++ )
    {
        for(int j = 0; j <= t; j ++ )
        {
            for(int k = 0; k <= n; k ++ )
            {
                dp[i % 2][j][k] = 0;
            }
        }
        for(int j = 0; j <= t; j ++ )
        {
            for(int k = 1; k < i; k ++ )
            dp[i % 2][j][1] = (dp[i % 2][j][1] + dp[(i - 1) % 2][j][k]) % mod;
            for(int k = 2; k <= min(i, j + 1); k ++ )
            dp[i % 2][j][k] = (dp[i % 2][j][k] + dp[(i - 1) % 2][j - k + 1][k - 1]) % mod;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++ )
    res = (res + dp[n % 2][t][i]) % mod;
    cout << res << endl;
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