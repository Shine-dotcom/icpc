#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 1), pre(n + 1), flag(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
        pre[i] = max(b[i], pre[i - 1]);
    }
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
    int ans = 0;
    for(int i = 1; i <= n; i += 2)
    {
        // cout << 222 << endl;
        if(i == 1)
        {
            if(b[i] >= b[i + 1])
            ans += max(b[i] - pre[i + 1] + 1, 0ll);
            // cout << "333 " << ans << endl;
            continue;
        }
        if(i == n)
        {
            if(b[i] >= b[i - 1])
            ans += max(b[i] - pre[i - 1] + 1, 0ll);
            // cout << "444 " << ans << endl;
            continue;
        }
        if(b[i] >= min(b[i + 1], b[i - 1]))
        ans += max(b[i] - min(pre[i + 1], pre[i - 1]) + 1, 0ll);
        // cout << "555 " << ans << endl;
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