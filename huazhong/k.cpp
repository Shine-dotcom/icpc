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
    if(n == 1 || m == 1)
    {
        cout << "NO" << endl;
        return;
    }
    int flag1 = 1, flag2 = 1, flag3 = 1, flag4 = 1;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i][1] == '#') flag3 = 0;
        if(a[i][m] == '#') flag4 = 0;
    }
    for(int j = 1; j <= m; j ++ )
    {
        if(a[1][j] == '#') flag1 = 0;
        if(a[n][j] == '#') flag2 = 0;
    }
    if(flag1 && flag4 || flag3 && flag2)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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