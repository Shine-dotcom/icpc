#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), cnt(1000005), flag(1000005);
    vector<pair<int, int>> seg(1000005);
    int mx = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        cnt[a[i]] ++;
        if(a[i] != a[i - 1] && !flag[a[i - 1]])
        {
            seg[a[i - 1]].first = i;
            flag[a[i - 1]] = 1;
        }
        seg[a[i]].second = i;
        mx = max(mx, cnt[a[i]]);
    }
    if(mx == n)
    {
        cout << 0 << endl;
        return;
    }
    int mn = 1e9;
    for(int i = 1; i <= 1e6; i ++ )
    {
        if(cnt[i] == 0) continue;
        if(cnt[i] == mx)
        {
            if(seg[i].first == seg[i].second)
            {
                cout << 0 << endl;
                return;
            }
            // cout << seg[i].first << ' ' << seg[i].second << endl;
            mn = min(mn, seg[i].second - seg[i].first + 1);
        }
    }
    cout << mn << endl;
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