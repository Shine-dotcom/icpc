#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> x(n + 1), t(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> x[i];
    for(int i = 1; i <= n; i ++ ) cin >> t[i];
    int ans = 0;
    vector<int> o, e, oi, ei;
    for(int i = 1; i <= n; i ++ )
    {
        if(x[i] % 2)
        {
            o.push_back(t[i]); // odd number
            oi.push_back(x[i]);
        }
        else
        {
            e.push_back(t[i]); // even number
            ei.push_back(x[i]);
        }
    }
    int m = o.size(), s0 = e.size();
    vector<int> cnt(2);
    for(int i = 0, j = 0; i < m; i ++ )
    {
        while(j < m && oi[j] - oi[i] < 2 * s)
        {
            cnt[o[j]] ++;
            ans += cnt[1 ^ o[j]];
            j ++;
        }
        cnt[o[i]] --;
    }
    cnt[0] = cnt[1] = 0;
    for(int i = 0, j = 0; i < s0; i ++ )
    {
        while(j < s0 && ei[j] - ei[i] < 2 * s)
        {
            cnt[e[j]] ++;
            ans += cnt[1 ^ e[j]];
            j ++;
        }
        cnt[e[i]] --;
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