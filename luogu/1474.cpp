#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int v, n;
    cin >> v >> n;
    vector<int> a(v + 1), dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= v; i ++ )
    {
        cin >> a[i];
        for(int j = 0; j <= n; j ++ )
        {
            if(j >= a[i]) dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[n] << endl;
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