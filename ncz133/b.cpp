#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    map<int, int> cnt;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    int mx = 0;
    for(auto &[i, y] : cnt)
    {
        mx = max(y, mx);
    }
    cout << max(0ll, mx - cnt[x]) << endl;
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