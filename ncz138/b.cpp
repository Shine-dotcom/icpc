#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y;
    cin >> x >> y;
    int tx = x, ty = y;
    int ans = 0;
    while(tx)
    {
        ans = max(ans, tx ^ y);
        tx >>= 1;
        ans = max(ans, tx ^ y);
    }
    while(ty)
    {
        ans = max(ans, ty ^ x);
        ty >>= 1;
        ans = max(ans, ty ^ x);
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