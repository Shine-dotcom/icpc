#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y;
    cin >> x >> y;
    int a = abs(x - y);
    int cnt = 0;
    for(int i = 1; i <= a; i ++ )
    {
        if(a % i == 0)
            cnt ++;
    }
    if(a == 0) cnt = 1;
    cout << cnt << endl;
    for(int i = 1; i <= x; i ++ )
    {
        cout << 1 << ' ';
    }
    for(int i = 1; i <= y; i ++ )
    {
        cout << -1 << ' ';
    }
    cout << endl;
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