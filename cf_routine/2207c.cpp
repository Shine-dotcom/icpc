#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    int ans = 0;
    vector<int> res(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int mn = h - a[i];
        res[i] = mn;
        for(int j = i + 1; j <= n; j ++ )
        {
            mn = min(h - a[j], mn);
            res[i] += mn;
        }
        mn = h - a[i];
        for(int j = i - 1; j >= 1; j -- )
        {
            mn = min(h - a[j], mn);
            res[i] += mn;
        }
    }
    // for(auto x : res)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    for(int i = 1; i <= n; i ++ )
    {
        int mx = a[i];
        int idx = i;
        for(int j = i; j <= n; j ++ )
        {
            if(mx < a[j])
            {
                idx = j;
                mx = a[j];
            }
            ans = max(ans, res[i] + res[j] - res[idx]);
        }
    }
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