#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    int ans = min((x2 - x1 + n) % n, (x1 - x2 + n) % n) + k;
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