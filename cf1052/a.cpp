#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        cnt[a] ++;
    }
    sort(cnt.begin(), cnt.end());
    int ans = 0, cnt2 = 0;
    for(int i = n; i >= 1; i -- )
    {
        if(cnt[i] == 0) break;
        cnt2 ++;
        ans = max(ans, cnt[i] * cnt2);
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