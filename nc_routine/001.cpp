#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            cin >> a[i][j];
        }
    }
    int q;
    cin >> q;
    while(q -- )
    {
        int x, y, v;
        cin >> x >> y >> v;
        if(x + y - 2 >= v)
        {
            dp[x][y] = -1e18;
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            dp[i][j] += max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[n][m] << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
}