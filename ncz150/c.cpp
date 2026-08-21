#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y;
    cin >> x >> y;
    int flag = 0;
    int cnt = 0;
    for(int i = 0; i <= 31; i ++ )
    {
        int xb = (x >> i) & 1;
        int yb = (y >> i) & 1;
        if(xb & yb) cnt ++;
        if(xb == 1 && yb == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        cout << 0 << endl;
        return;
    }
    cout << (1 << cnt) << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}