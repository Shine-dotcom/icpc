#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    int x, y;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            if(a[i][j] == '#')
            {
                y = i, x = j;
            }
        }
    }
    int x0, y0;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i][1] == '*')
        {
            y0 = i;
            break;
        }
    }
    for(int j = 1; j <= m; j ++ )
    {
        if(a[1][j] == '*')
        {
            x0 = j;
            break;
        }
    }
    cout << x - x0 << ' ' << y0 - y << endl;
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