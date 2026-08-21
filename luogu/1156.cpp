#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int t, h, f;
    bool operator < (const node &u) const {
        return t < u.t;
    }
};
void solve()
{
    int d, g;
    cin >> d >> g;
    vector<int> dp(d + 1);
    dp[0] = 10;
    vector<node> a(g + 1);
    for(int i = 1; i <= g; i ++ )
    {
        cin >> a[i].t >> a[i].f >> a[i].h;
    }
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= g; i ++ )
    {
        for(int j = d; j >= 0; j -- )
        {
            if(dp[j] < a[i].t) continue;
            if(j + a[i].h >= d)
            {
                cout << a[i].t << endl;
                return;
            }
            dp[j + a[i].h] = max(dp[j], dp[j + a[i].h]);
            dp[j] += a[i].f;
        }
    }
    cout << dp[0] << endl;
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