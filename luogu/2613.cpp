#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int qpow(int a, int b, int mod)
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