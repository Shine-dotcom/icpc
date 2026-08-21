#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            cin >> a[i][j];
        }
    }
    int h, w;
    cin >> h >> w;
    for(int i = h; i <= n; i ++ )
    {
        for(int j = w; j <= m; j ++ )
        {
            if(a[i][j] == a[i - h + 1][j] && a[i][j] == a[i][j - w + 1] && a[i][j] == a[i - h + 1][j - w + 1])
            {
                cout << "YES" << endl;
                return;
            }
        }
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