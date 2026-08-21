#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y;
    cin >> x >> y;
    if(x <= y && (x - y) % 3 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if(x > y && (x - y) % 2 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
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