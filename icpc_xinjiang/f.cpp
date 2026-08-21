#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node {
    int h, a, b;
    bool operator < (const node &u) const {
        return h < u.h;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<node> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i].h;
    for(int i = 1; i <= n; i ++ ) cin >> a[i].a;
    for(int i = 1; i <= n; i ++ ) cin >> a[i].b;
    sort(a.begin() + 1, a.end());
    vector<int> pre(n + 1), suf(n + 1);
    suf[n] = a[n].b;
    for(int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i].a;
    for(int i = n - 1; i >= 1; i -- ) suf[i] = suf[i + 1] + a[i].b;
    int mx = 0;
    for(int i = 0; i < n; i ++ )
    {
        mx = max(mx, pre[i] + suf[i + 1]);
    }
    mx = max(mx, pre[n]);
    cout << mx << endl;
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