#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(3);
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        cnt[x % 3] ++;
    }
    int ans = cnt[0];
    ans += min(cnt[1], cnt[2]);
    ans += max(cnt[1] - min(cnt[1], cnt[2]), cnt[2] - min(cnt[1], cnt[2])) / 3;
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