#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y, d;
    cin >> x >> y >> d;
    if(x - d == y || x + d == y)
    {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
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