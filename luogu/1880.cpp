#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 210;
int dp[N][N];
void solve()
{
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(2 * n);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i < n; i ++ ) a.push_back(a[i]);
    for(int i = 1; i < 2 * n; i ++ ) pre[i] = pre[i - 1] + a[i];
    for(int i = 1; i < 2 * n; i ++ ) dp[i][i] = 0;
    int ans_min = 1e18;
    for(int len = 2; len <= n; len ++ )
    {
        for(int l = 1; l < min(2 * n, l + len); l ++ )
        {
            int r = min(l + len - 1, 2 * n - 1);
            for(int k = l; k < r; k ++ )
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        ans_min = min(ans_min, dp[i][i + n - 1]);
    }
    cout << ans_min << endl;
    memset(dp, 0, sizeof(dp));
    int ans_max = 0;
    for(int len = 2; len <= n; len ++ )
    {
        for(int l = 1; l + len - 1 <= 2 * n - 1; l ++ )
        {
            int r = l + len - 1;
            for(int k = l; k < r; k ++ )
            {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        ans_max = max(ans_max, dp[i][i + n - 1]);
    }
    cout << ans_max << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- ) solve();
    return 0;
}