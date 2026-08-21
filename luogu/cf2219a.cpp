#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int p, q, k = 0;
    cin >> p >> q;
    k = 2 * q + p;
    k = 2 * k + 1;
    int n = -1, m = -1;
    for(int i = 3; i <= sqrt(k); i += 2 )
    {
        if(k % i == 0 && (k / i) % 2)
        {
            int u = i, v = k / i;
            u /= 2, v /= 2;
            if(q <= u * (v + 1) && q <= v * (u + 1))
            {
                n = u, m = v;
                break;
            }
        }
    }
    if(n == -1)
    {
        cout << -1 << endl;
        return;
    }
    cout << n << ' ' << m << endl;
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