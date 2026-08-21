#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    int mx = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        cnt[x] ++;
        mx = max(mx, x);
    }
    if(cnt[mx] == n)
    {
        if(mx <= 1)
        {
            cout << n << endl;
            return;
        }
        cout << mx * n << endl;
        return;
    }
    int ans = n * mx;
    int i;
    int c = 0;
    for(i = 0; cnt[i]; i ++ )
    {
        if(i == mx - 1)
        {
            i += 2;
            break;
        }
        c ++;
        ans += (i + 1);
    }
    ans += i * (n - c - 1);
    // cout << i << ' ' << n - c - 1 << endl;
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