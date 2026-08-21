#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 998244353;
int ksm(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int fact(int x)
{
    int res = 1;
    for(int i = 2; i <= x; i ++ )
    {
        res = (res * i) % mod;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int j = 0, o = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(s[i] == 'o') o ++;
        if(s[i] == 'j') j ++;
    }
    int j0 = (n + 1) / 2, o0 = n / 2;
    if(j0 < j || o0 < o)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    ans = fact(j0) * ksm(fact(j0 - j), mod - 2) % mod;
    // cout << ans << endl;
    ans = (ans * fact(o0) * ksm(fact(o0 - o), mod - 2)) % mod;
    // cout << ans << endl;
    ans = (ans * fact(n - j - o)) % mod;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}