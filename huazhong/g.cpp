#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), premin(n + 1, 1e18), premax(n + 1), sufmin(n + 2, 1e18), sufmax(n + 2);
    int mx = 0, mn = 1e18;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        premin[i] = min(premin[i - 1], a[i]);
        premax[i] = max(premax[i - 1], a[i]);
    }
    for(int i = n; i >= 1; i -- )
    {
        sufmin[i] = min(sufmin[i + 1], a[i]);
        sufmax[i] = max(sufmax[i + 1], a[i]);
    }
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << premin[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << premax[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << sufmin[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << sufmax[i] << ' ';
    // }
    // cout << endl;
    int ans_mx = 0, ans_mn = 1e18;
    mx = 0, mn = 1e18;
    for(int i = 1; i <= n - k + 1; i ++ )
    {
        // cout << i - 1 << ' ' << i + k << endl;
        mn = min(premin[i - 1], sufmin[i + k]);
        mx = max(premax[i - 1], sufmax[i + k]);
        ans_mn = min(ans_mn, mx - mn);
        ans_mx = max(ans_mx, mx - mn);
    }
    cout << ans_mx << ' ' << ans_mn << endl;
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