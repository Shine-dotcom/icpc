#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> c[i];
    }
    vector<vector<int>> dp(n + 1, vector<int> (5, 1e18));
    if(a[1] > 2)
        dp[1][0] = 2 * c[1];
    if(a[1] > 1)
        dp[1][1] = c[1];
    dp[1][2] = 0;
    dp[1][3] = b[1];
    dp[1][4] = 2 * b[1];
    for(int i = 2; i <= n; i ++ )
    {
        for(int j = -2; j <= 2; j ++ )
        {
            for(int k = -2; k <= 2; k ++ )
            {
                if(a[i] + j == a[i - 1] + k)
                {
                    continue;
                }
                if(a[i] + j <= 0)
                {
                    continue;
                }
                if(a[i] != a[i - 1])
                {
                    dp[i][j + 2] = min(dp[i][j + 2], dp[i - 1][k + 2]);
                    continue;
                }
                if(j <= 0)
                {
                    dp[i][j + 2] = min(dp[i][j + 2], dp[i - 1][k + 2] + abs(j) * c[i]);
                    continue;
                }
                dp[i][j + 2] = min(dp[i][j + 2], dp[i - 1][k + 2] + j * b[i]);
            }
        }
    }
    int ans = 1e18;
    for(int i = 0; i < 5; i ++ )
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
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