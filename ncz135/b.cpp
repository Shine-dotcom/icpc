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
        a[i] -= i;
    }
    map<int, int> cnt;
    for(int i = 1; i <= n; i ++ )
    {
        cnt[a[i]] ++;
    }
    int ans = 0;
    for(auto x : cnt)
    {
        ans = max(ans, x.second);
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