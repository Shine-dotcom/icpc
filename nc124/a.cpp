#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y;
    cin >> x >> y;
    int x0 = 1, y0 = 1;
    if(x < 0)
    {
        x0 = -x0;
    }
    if(y < 0)
    {
        y0 = -y0;
    }
    if(x0 == x && y0 == y)
    {
        if(x0 < 0)
        {
            x0 --;
        }
        else
        {
            x0 ++;
        }
    }
    cout << x0 << ' ' << y0 << endl;
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
}
