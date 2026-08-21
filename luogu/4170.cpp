#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 55;
int dp[N][N];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i ++ ) dp[i][i] = 1;
    for(int len = 2; len <= n; len ++ )
    {
        for(int i = 1; i + len - 1 <= n; i ++ )
        {
            int j = i + len - 1;
            if(s[i] != s[j])
            {
                for(int k = i; k < j; k ++ )
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[1][n] << endl;
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