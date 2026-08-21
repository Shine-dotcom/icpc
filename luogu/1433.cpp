#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
double dp[(1 << 16) + 10][20];
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i ++ )
    {
        for(int j = 0; j < n; j ++ )
        {
            dp[i][j] = 1e9;
        }
    }
    vector<pair<double, double>> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i].first >> a[i].second;
    for(int i = 0; i < n; i ++ )
    {
        dp[(1 << i)][i] = sqrt(a[i].first * a[i].first + a[i].second * a[i].second);
    }
    for(int i = 1; i < (1 << n); i ++ )
    {
        for(int j = 0; j < n; j ++ )
        {
            if((i & (1 << j)) == 0) continue;
            int x = i - (1 << j);
            for(int k = 0; k < n; k ++ )
            {
                double dis = sqrt((a[j].first - a[k].first) * (a[j].first - a[k].first) + (a[j].second - a[k].second) * (a[j].second - a[k].second));
                if(k == j) continue;
                if((i & (1 << k)) == 0) continue;
                dp[i][j] = min(dp[i][j], dp[x][k] + dis);
                // cout << i << ' ' << j << ' ' << x << ' ' << k << ' ' << dis << endl;
            }
        }
    }
    double ans = 1e9;
    for(int i = 0; i < n; i ++ )
    {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << fixed << setprecision(2) << ans << endl;
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