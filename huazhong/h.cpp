#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    while(q -- )
    {
        vector<int> cnt(n + 1);
        int l, r, t = 0;
        cin >> l >> r;
        int len = r - l + 1;
        for(int i = l; i <= r; i ++ )
        {
            if(a[i] >= len) t ++;
            else cnt[a[i]] ++;
        }
        int ans = 0;
        for(int i = len; i >= 1; i -- )
        {
            ans = (ans + i * t * t) % mod;
            t += cnt[i - 1];
        }
        cout << ans << endl;
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