#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct task {
    int p, t;
    bool operator > (const task &u) const {
        return p > u.p;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 2);
    vector<task> a(k + 1);
    for(int i = 1; i <= k; i ++ )
    {
        cin >> a[i].p >> a[i].t;
    }
    sort(a.begin() + 1, a.end(), [&](task x, task y) {
        return x > y;
    });
    int cnt = 1;
    // dp[n] = (a[cnt].p == n ? 0 : 1);
    // while(cnt <= k && a[cnt].p == n) cnt ++;
    for(int i = n; i >= 1; i -- )
    {
        if(cnt > k || i != a[cnt].p)
        {
            dp[i] = dp[i + 1] + 1;
            continue;
        }
        while(cnt <= k && i == a[cnt].p)
        {
            dp[i] = max(dp[i], dp[i + a[cnt ++ ].t]);
        }
    }
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    cout << dp[1] << endl;
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