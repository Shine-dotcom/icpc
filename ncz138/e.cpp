#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    vector<int> dp(n + 1);
    int max0 = -1e18, max1 = -1e18;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i] & 1)
        {
            dp[i] = max(dp[i - 1], a[i] + max1);
            max1 = max(dp[i - 1] + a[i], max1);
        }
        else
        {
            dp[i] = max(dp[i - 1], a[i] + max0);
            max0 = max(dp[i - 1] + a[i], max0);
        }
    }
    cout << dp[n] << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
}