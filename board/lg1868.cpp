#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1.5e5 + 10;
pair<int, int> a[N];
int n, dp[N];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int Lower_Bound(int l, int r, int val)
{
    while(l < r)
    {
        // cout << "l r " << l << ' ' << r << endl;
        int mid = (l + r + 1) / 2;
        // cout << val << ' ' << a[mid].second << endl;
        if(val > a[mid].second) l = mid;
        else r = mid - 1;
        // cout << "mid: " << mid << endl;
    }
    return l;
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i ++ )
    {
        // cout << a[i].first << ' ' << a[i].second << endl;
    }
    for(int i = 1; i <= n; i ++ )
    {
        int j = Lower_Bound(0, i - 1, a[i].first);
        // cout << j << endl;
        dp[i] = max(dp[i - 1], dp[j] + a[i].second - a[i].first + 1);
    }
    // for(int i = 0; i <= n; i ++ ) cout << dp[i] << ' ';
    // cout << endl;
    cout << dp[n] << endl;
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