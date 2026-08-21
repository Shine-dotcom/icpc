#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if(n == 1 || m == 1)
    {
        int cnt = 0;
        if(k == 0 || k == n * m)
        {
            cout << "No" << endl;
            return;
        }
        if(n == 1)
        {
            for(int i = 1; i <= m && cnt < k; i += 2)
            {
                g[1][i] = 1;
                cnt ++;
            }
            if(cnt < k)
            {
                cout << "No" << endl;
                return;
            }
        }
        if(m == 1)
        {
            for(int i = 1; i <= n && cnt < k; i += 2)
            {
                g[i][1] = 1;
                cnt ++;
            }
            if(cnt < k)
            {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
        for(int i = 1; i <= n; i ++ )
        {
            for(int j = 1; j <= m; j ++ )
            {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
    vector<vector<int>> g(n + 1, vector<int> (m + 1));
    int cnt = 0;
    if(k < max(n / 2, 1ll) * max(m / 2, 1ll))
    {
        cout << "No" << endl;
        return;
    }
    int flag = 0;
    if(k < n * m - k) flag = 1;
    for(int i = 2; i <= n && cnt < k; i += 2)
    {
        for(int j = 1 + flag; j <= m && cnt < k; j += 2)
        {
            g[i][j] = 1;
            cnt ++;
        }
    }
    for(int i = 1; i <= n && cnt < k; i += 2)
    {
        for(int j = 1; j <= m && cnt < k; j ++ )
        {
            if(g[i][j]) continue;
            g[i][j] = 1;
            cnt ++;
        }
    }
    if(cnt < k)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            cout << g[i][j];
        }
        cout << endl;
    }
//     cout << cnt << ' ' << k << endl;
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