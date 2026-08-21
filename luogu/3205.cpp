#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1010;
int dp[N][N][2];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) dp[i][i][0] = 1;
    for(int len = 2; len <= n; len ++ )
    {
        for(int l = 1; l + len - 1 <= n; l ++ )
        {
            int r = l + len - 1;
            if(a[l] < a[l + 1]) dp[l][r][0] += dp[l + 1][r][0];
            if(a[r] > a[r - 1]) dp[l][r][1] += dp[l][r - 1][1];
            if(a[l] < a[r]) dp[l][r][0] += dp[l + 1][r][1];
            if(a[r] > a[l]) dp[l][r][1] += dp[l][r - 1][0];
            dp[l][r][0] %= 19650827;
            dp[l][r][1] %= 19650827;
        }
    }
    // cout << dp[1][n][1] << ' ' << dp[1][n][0] << endl;
    // for(int i = 0; i <= 1; i ++ )
    // {
    //     for(int j = 1; j <= n; j ++ )
    //     {
    //         for(int k = 1; k <= n; k ++ )
    //         {
    //             cout << dp[j][k][i] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    cout << (dp[1][n][0] + dp[1][n][1]) % 19650827 << endl;
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