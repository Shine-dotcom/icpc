#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 1), cnt(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
        cnt[b[i]] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        ans += cnt[i];
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