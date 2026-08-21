#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    if(n <= 2 && m <= 2)
    {
        cout << 1 << endl;
        return;
    }
    if(n == 3 && m == 2 || n == 2 && m == 3)
    {
        cout << 2 << endl;
        return;
    }
    if(n == 3 && m == 3)
    {
        cout << 8 << endl;
        return;
    }
    cout << n * m << endl;
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
