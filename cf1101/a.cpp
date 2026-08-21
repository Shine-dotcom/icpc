#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = 1e9;
    for(int i = 1, j = 1; i <= n; i ++ )
    {
        while(j < n && a[j + 1] == a[i]) j ++;
        int mx = max(n - j, i - 1);
        ans = min(mx, ans);
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