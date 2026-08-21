#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 998244353;
int q_mul(int a, int b)
{
    int res = 0;
    while(b)
    {
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    int cntr = (n + 1) / 4;
    int cntl = (x + 4) / 4;
    int ans = (q_mul(cntr - cntl + 1, cntl)) % mod;
    cntr = (n - 1) / 4;
    cntl = (x + 2) / 4;
    ans = (ans + q_mul(cntr - cntl + 1, cntl) % mod) % mod;
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