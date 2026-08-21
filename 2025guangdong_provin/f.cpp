#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int cnt[100010];
void solve()
{
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        if(a[i] <= 1e5) cnt[a[i]] ++;
        mx = max(a[i], mx);
    }
    if(cnt[0] == 0)
    {
        cout << 1 << endl;
        return;
    }
    int mn = cnt[0];
    for(int i = 1; i <= 1e5 + 5; i ++ )
    {
        if(cnt[i] == 0 && i < mx)
        {
            cout << i << endl;
            return;
        }
        if(i > mx) break;
        mn = min(mn, cnt[i]);
    }
    int ans = (mx + 1) * mn + 1;
    // cout << mx << ' ' << mn << endl;
    for(int i = 0; i <= mx; i ++ )
    {
        if(cnt[i] == mn) break;
        ans ++;
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