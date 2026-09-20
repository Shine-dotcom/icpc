#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    if(n == 1)
    {
        cout << a[1] << endl;
        return;
    }
    int mx = -1e9;
    int idx = 0;
    for(int i = m; i <= n; i ++ )
    {
        if(mx <= a[i])
        {
            mx = a[i];
            idx = i;
        }
    }
    // cout << idx << endl;
    sort(a.begin() + 1, a.begin() + idx);
    int ans = 0;
    for(int i = 1; i < m; i ++ )
    {
        ans -= a[i];
        // cout << a[i] << ' ';
    }
    // cout << endl;
    ans += a[idx] * m;
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
    return 0;
}