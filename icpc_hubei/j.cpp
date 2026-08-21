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
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a;
        sum = (sum + a) % mod;
    }
    sum = (sum * ksm(n, mod - 2)) % mod;
    cout << sum << endl;
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