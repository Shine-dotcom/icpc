#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 5000;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int> (10010, 1e9));
    dp[0][N] = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        a[i] = x - y;
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 5000; j >= -5000; j -- )
        {
            dp[i][j + N] = min(dp[i - 1][j - a[i] + N] + 1, dp[i - 1][j + a[i] + N]);
        }
    }
    int mn = 1e9, idx = 0;
    for(int i = 0; i <= 5000; i ++ )
    {
        mn = min(dp[n][-i + N], dp[n][i + N]);
        if(mn <= 1000)
        {
            cout << mn << endl;
            return;
        }
        // cout << dp[i] << endl;
    }
    // for(int i = -30; i <= 30; i ++ )
    // {
    //     cout << i << ' ' << dp[n][N + i] << endl;
    // }
    // cout << endl;
    // cout << mn << endl;
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