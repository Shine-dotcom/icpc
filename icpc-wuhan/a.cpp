#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int val, l = 0, r = 1e18;
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<node> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i].val;
    }
    int ans = 0;
    while(q -- )
    {
        int p, l, r;
        cin >> p >> l >> r;
        a[p].l = max(l, a[p].l);
        a[p].r = min(r, a[p].r);
    }
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i].l > a[i].r)
        {
            cout << -1 << endl;
            return;
        }
        if(a[i].l > a[i].val)
        {
            ans += a[i].l - a[i].val;
        }
        if(a[i].r < a[i].val)
        {
            ans += a[i].val - a[i].r;
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