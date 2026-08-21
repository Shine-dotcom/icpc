#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1800;
bool dp[N][N];
int a[N];
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i <= n; i ++ )
    {
        a[i] = 0;
        for(int j = 0; j <= n; j ++ )
        {
            dp[i][j] = 0;
        }
    }
    double ans = -1;
    int sum = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = sum / 2; j >= 0; j -- )
        {
            for(int k = sum / 2; k >= 0; k -- )
            {
                if(j >= a[i]) dp[j][k] |= dp[j - a[i]][k];
                if(k >= a[i]) dp[j][k] |= dp[j][k - a[i]];
            }
        }
    }
    for(int j = sum / 2; j >= 0; j -- )
    {
        for(int k = sum / 2; k >= 0; k -- )
        {
            if(dp[j][k])
            {
                if(2 * j >= sum)
                {
                    continue;
                }
                if(2 * k >= sum)
                {
                    continue;
                }
                if(sum >= 2 * (j + k))
                {
                    continue;
                }
                double p = (double)sum / 2;
                double a = j;
                double b = k;
                double c = sum - j - k;
                double res = sqrt(p * (p - a) * (p - b) * (p - c));
                ans = max(ans, res);
            }
        }
    }
    if(ans == -1) cout << ans << endl;
    else cout << (int)(ans * 100) << endl;
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