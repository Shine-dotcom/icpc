#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    if(n > 1 && m > 1)
    {
        cout << -1 << endl;
        return;
    }
    if(n > 1)
    {
        for(int i = 1; i <= n - 1; i ++ )
        {
            cout << 1 << endl;
        }
        cout << 0 << endl;
        return;
    }
    if(m > 1)
    {
        for(int i = 1; i <= m - 1; i ++ )
        {
            cout << 1;
        }
        cout << 0 << endl;
        return;
    }
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