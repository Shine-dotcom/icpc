#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a, b, c, l, r;
    cin >> a >> b >> c >> l >> r;
    if(a == b && b == c)
    {
        a = 0, b = 0;
    }
    else if(a == b)
    {
        a = 0;
    }
    else if(b == c)
    {
        b = 0;
    }
    int cnt = 3;
    if(a < l || a > r)
    {
        cnt --;
    }
    if(b < l || b > r)
    {
        cnt --;
    }
    if(c < l || c > r)
    {
        cnt --;
    }
    cout << r - l - cnt + 1 << endl;
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