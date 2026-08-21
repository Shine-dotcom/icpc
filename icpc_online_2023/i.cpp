#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M = 70;
int dp[2][M][8];
const int mod = 998244353;
void solve()
{
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    if(s[1] == '?')
    {
        for(int i = 1; i <= 26; i ++ ) dp[1][i][2] = 1;
        for(int i = 27; i <= 52; i ++ ) dp[1][i][4] = 1;
        for(int i = 53; i <= 62; i ++ ) dp[1][i][1] = 1;
    }
    if(s[1] >= 'a' && s[1] <= 'z')
    {
        dp[1][s[1] - 'a' + 1][2] = 1;
        dp[1][s[1] - 'a' + 27][4] = 1;
    }
    if(s[1] >= 'A' && s[1] <= 'Z')
    {
        dp[1][s[1] - 'A' + 27][4] = 1;
    }
    if(s[1] >= '0' && s[1] <= '9')
    {
        dp[1][s[1] - '0' + 53][1] = 1;
    }
    for(int i = 2; i <= n; i ++ )
    {
        int sum[8];
        memset(sum, 0, sizeof(sum));
        memset(dp[i % 2], 0, sizeof(dp[i % 2]));
        for(int j = 1; j <= 62; j ++ )
            for(int k = 0; k < 8; k ++ ) sum[k] = (sum[k] + dp[(i - 1) % 2][j][k]) % mod;
        if(s[i] == '?')
        {
            for(int j = 1; j <= 26; j ++ )
                for(int k = 0; k < 8; k ++ )
                    dp[i % 2][j][k | 2] = ((dp[i % 2][j][k | 2] + sum[k]) % mod - dp[(i - 1) % 2][j][k] + mod) % mod;
            for(int j = 27; j <= 52; j ++ )
                for(int k = 0; k < 8; k ++ )
                    dp[i % 2][j][k | 4] = ((dp[i % 2][j][k | 4] + sum[k]) % mod - dp[(i - 1) % 2][j][k] + mod) % mod;
            for(int j = 53; j <= 62; j ++ )
                for(int k = 0; k < 8; k ++ )
                    dp[i % 2][j][k | 1] = ((dp[i % 2][j][k | 1] + sum[k]) % mod - dp[(i - 1) % 2][j][k] + mod) % mod;
        }
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            int j = s[i] - 'a' + 27, j0 = s[i] - 'a' + 1;
            for(int k = 0; k < 8; k ++ )
            {
                dp[i % 2][j0][k | 2] = ((dp[i % 2][j0][k | 2] + sum[k]) % mod - dp[(i - 1) % 2][j0][k] + mod) % mod;
                dp[i % 2][j][k | 4] = ((dp[i % 2][j][k | 4] + sum[k]) % mod - dp[(i - 1) % 2][j][k] + mod) % mod;
            }
        }
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            int j = s[i] - 'A' + 27;
            for(int k = 0; k < 8; k ++ )
            {
                dp[i % 2][j][k | 4] = ((dp[i % 2][j][k | 4] + sum[k]) % mod - dp[(i - 1) % 2][j][k] + mod) % mod;
            }
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            int j = s[i] - '0' + 53;
            for(int k = 0; k < 8; k ++ )
            {
                dp[i % 2][j][k | 1] = ((dp[i % 2][j][k | 1] + sum[k]) % mod - dp[(i - 1) % 2][j][k] + mod) % mod;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= 62; i ++ ) ans = (ans + dp[n % 2][i][7]) % mod;
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