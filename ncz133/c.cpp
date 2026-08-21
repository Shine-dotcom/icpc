#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, l, r;
    cin >> x >> l >> r;
    for(int i = 1; i * i <= x; i ++ )
    {
        if(x % (i * i) == 0) x /= (i * i);
    }
    for(int i = 1; i * i * x <= r; i ++ )
    {
        if(i * i * x >= l)
        {
            cout << i * i * x << endl;
            return;
        }
    }
    cout << -1 << endl;
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