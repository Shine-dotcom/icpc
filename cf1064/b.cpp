#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    if(a == b)
    {
        cout << 1 << endl;
        return;
    }
    cout << (n > a / b ? 2 : 1) << endl;
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