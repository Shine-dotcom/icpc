#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2)
    {
        cout << x1 + 1 << ' ' << y1 << ' ';
        cout << x2 + 1 << ' ' << y2 << endl;
    }
    if(y1 == y2)
    {
        cout << x1 << ' ' << y1 + 1 << ' ';
        cout << x2 << ' ' << y2 + 1 << endl;
    }
    cout << x1 << ' ' << y2 << ' ';
    cout << x2 << ' ' << y1 << endl;
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
}
