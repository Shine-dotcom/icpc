#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > c && b < d)
    {
        cout << "A" << endl;
        return;
    }
    cout << "B" << endl;
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