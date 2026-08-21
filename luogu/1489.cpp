#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M = 8e3, N = 200;
bool dp[N + 10][M + 10];
int a[N + 10];
void solve()
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    int sum = 0;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];
    dp[0][0] = 1;
    for(int k = 1; k <= n; k ++ )
    {
        for(int i = n / 2 + 1; i >= 1; i -- )
        {
            for(int j = 8000; j >= a[k]; j -- )
            {
                dp[i][j] |= dp[i - 1][j - a[k]];
            }
        }
    }
    int mn = 1e9, ans = 0;
    for(int j = 0; j <= sum; j ++ )
    {
        if(dp[n / 2][j])
        {
            if(mn > abs(sum - 2 * j))
            {
                ans = j;
                mn = abs(sum - 2 * j);
            }
        }
    }
    cout << min(ans, sum - ans) << ' ' << max(ans, sum - ans) << endl;
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