#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    int res = 0;
    while(h -- )
    {
        int x, y, z;
        cin >> x >> y >> z;
        res = (res + ((n *(n + 1) / 2 + m * (m + 1) / 2 + n * y + m * x - (x + y)) % mod) * z) % mod;
    }
    cout << res << endl;
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