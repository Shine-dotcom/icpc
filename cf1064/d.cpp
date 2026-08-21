#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), cnt(n + 1);
    vector<int> dp(n + 1);
    dp[0] = 1;
    int mx = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        cnt[a[i]] ++;
        mx = max(cnt[a[i]], mx);
    }
    for(int i = 1; i <= n; i ++ )
    {
        if(cnt[i])
        {
            for(int j = n; j >= cnt[i]; j -- )
            {
                dp[j] = (dp[j] + dp[j - cnt[i]] * cnt[i]) % mod;
            }
        }
    }
    int ans = 0;
    for(int i = mx; i <= n; i ++ )
    ans = (ans + dp[i]) % mod;
    cout << ans << endl;
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