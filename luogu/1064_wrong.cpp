#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int> (n + 1));
    vector<vector<int>> v(m + 1, vector<int> (3)), w(m + 1, vector<int> (3));
    for(int i = 1; i <= m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0)
        {
            v[i][0] = a;
            w[i][0] = b;
        }
        else
        {
            if(!v[c][1])
            {
                v[c][1] = a;
                w[c][1] = b;
            }
            else
            {
                v[c][2] = a;
                w[c][2] = b;
            }
        }
    }
    for(int i = 1; i <= m; i ++ )
    {
        for(int j = 0; j <= n; j ++ )
        {
            if(j >= v[i][0])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i][0]] + v[i][0] * w[i][0]);
            }
            if(j >= v[i][0] + v[i][1])
            {
                int t = v[i][0] + v[i][1];
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + v[i][0] * w[i][0] + v[i][1] * w[i][1]);
            }
            if(j >= v[i][0] + v[i][2])
            {
                int t = v[i][0] + v[i][2];
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + v[i][0] * w[i][0] + v[i][2] * w[i][2]);
            }
            if(j >= v[i][0] + v[i][1] + v[i][2])
            {
                int t = v[i][0] + v[i][1] + v[i][2];
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + v[i][0] * w[i][0] + v[i][1] * w[i][1] + v[i][2] * w[i][2]);
            }
        }
    }
    cout << dp[m][n] << endl;
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