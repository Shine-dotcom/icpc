#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 55;
int dp[N][N][2];
void solve()
{
    int n, c;
    memset(dp, 0x3f, sizeof(dp));
    cin >> n >> c;
    vector<int> a(n + 1), w(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i] >> w[i];
    vector<int> sum(n + 1);
    dp[c][c][0] = dp[c][c][1] = 0;
    for(int i = 1; i <= n; i ++ ) sum[i] = sum[i - 1] + w[i];
    for(int len = 2; len <= n; len ++ )
    {
        for(int l = 1; l + len - 1 <= n; l ++ )
        {
            int r = l + len - 1;
            auto sum_w = [&](int l, int r) -> int {
                return sum[n] - sum[r] + sum[l - 1];
            };
            dp[l][r][0] = min(dp[l + 1][r][0] + (a[l + 1] - a[l]) * sum_w(l + 1, r), dp[l + 1][r][1] + (a[r] - a[l]) * sum_w(l + 1, r));
            dp[l][r][1] = min(dp[l][r - 1][1] + (a[r] - a[r - 1]) * sum_w(l, r - 1), dp[l][r - 1][0] + (a[r] - a[l]) * sum_w(l, r - 1));
        }
    }
    // for(int i = 0; i <= 1; i ++ )
    // {
    //     for(int j = 1; j <= n; j ++ )
    //     {
    //         for(int k = 1; k <= n; k ++ )
    //         {
    //             cout << (dp[j][k][i] >= 1e9 ? -1 : dp[j][k][i]) << '\t';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << min(dp[1][n][0], dp[1][n][1]) << endl;
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