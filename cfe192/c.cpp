#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<int> cnt(n + 1);
    int tmp = -1, len = -1, q = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i] != tmp)
        {
            q ++;
            if(len != -1) cnt[len] ++;
            len = 1;
            tmp = a[i];
            continue;
        }
        len ++;
    }
    cnt[len] ++;
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << i << ' ' << cnt[i] << endl;
    // }
    int sum = 0, ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(cnt[i])
        {
            if(n - sum - (i - 1) * q <= k && (k - n + sum) % q == 0) ans ++;
            sum += cnt[i] * i;
            q -= cnt[i];
        }
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
        // cout << endl;
    }
}