#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp(100005);
    for(int i = 1; i < k; i ++ )
    {
        dp[i] = 1;
    }
    dp[k] = 2;
    for(int i = k + 1; i <= 100000; i ++ )
    {
        dp[i] = (dp[i - 1] + dp[i - k]) % mod;
    }
    vector<int> sum(100005);
    for(int i = 1; i <= 100000; i ++ )
    {
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    while(n -- )
    {
        int a, b;
        cin >> a >> b;
        cout << (sum[b] - sum[a - 1] + mod) % mod << endl;
    }
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