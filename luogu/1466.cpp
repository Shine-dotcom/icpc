#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int dp[45][2000];
void init()
{
    dp[0][0] = 1;
    for(int i = 1; i <= 40; i ++ )
    {
        for(int j = 0; j <= i * (i + 1) / 2; j ++ )
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= i) dp[i][j] += dp[i - 1][j - i];
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    if(n * (n + 1) % 4)
    {
        cout << 0 << endl;
        return;
    }
    int m = n * (n + 1) / 4;
    cout << dp[n][m] / 2 << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    init();
    while(t -- )
    {
        solve();
    }
}