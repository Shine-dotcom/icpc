#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> dp(210), v(n + 1), w(n + 1);
    int len_sum = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> v[i] >> w[i];
        len_sum += v[i];
    }
    for(int i = 1; i <= len_sum; i ++ )
    {
        dp[i] = 10000;
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = len_sum; j >= v[i]; j -- )
        {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    int ans = 0;
    for(int i = len_sum; i >= 0; i -- )
    {
        if(dp[i] <= len_sum - i)
        {
            ans = len_sum - i;
            break;
        }
    }
    cout << ans << endl;
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