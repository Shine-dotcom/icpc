#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int m, s, t;
    cin >> m >> s >> t;
    vector<int> dp(t + 1);
    for(int i = 1; i <= t; i ++ )
    {
        if(m >= 10)
        {
            m -= 10;
            dp[i] = dp[i - 1] + 60;
            continue;
        }
        m += 4;
        dp[i] = dp[i - 1];
    }
    for(int i = 1; i <= t; i ++ )
    {
        if(dp[i] < dp[i - 1] + 17)
        {
            dp[i] = dp[i - 1] + 17;
        }
        if(dp[i] >= s)
        {
            cout << "Yes" << endl;
            cout << i << endl;
            return;
        }
    }
    cout << "No" << endl;
    cout << dp[t] << endl;
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