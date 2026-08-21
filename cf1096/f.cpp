#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1, 1e9);
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    for(int i = n - 1; i >= 1; i -- )
    {
        cnt[i] += cnt[i + 1];
    }
    int ed = 0;
    for(int i = 1; i <= n; i ++ )
    {
        ed += cnt[i] * (2 * n - cnt[i] + 1) / 2;
    }
    int st = 0;
    for(int i = 1; i <= n; i ++ )
    {
        st += i * a[i];
    }
    int res = ed - st;
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        ans = max(ans, res + i - n + cnt[a[i]] - 1);
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
    return 0;
}