#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a, b, p;
    cin >> a >> b >> p;
    auto q_mul = [&](int a, int b, int p) -> int {
        int res = 0;
        while(b)
        {
            if(b & 1) res = (res + a) % p;
            a = (a + a) % p;
            b >>= 1;
        }
        return res;
    };
    auto q_mod = [&](int a, int b, int p) -> int {
        int res = 1;
        while(b)
        {
            if(b & 1) res = q_mul(res, a, p) % p;
            a = q_mul(a, a, p) % p;
            b >>= 1;
        }
        return res;
    };
    cout << q_mod(a, b, p) << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- ) solve();
    return 0;
}