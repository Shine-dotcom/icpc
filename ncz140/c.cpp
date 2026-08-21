#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        s[i] = " " + s[i];
        for(int j = 1; j <= m; j ++ )
        {
            a[i][j] = s[i][j] - '0';
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            if(i < n && j < m)
            {
                int tmp = a[i][j] ^ a[i + 1][j] ^ a[i][j + 1];
                if(tmp == 3)
                {
                    ans ++;
                }
            }
            if(i > 1 && j < m)
            {
                int tmp = a[i][j] ^ a[i - 1][j] ^ a[i][j + 1];
                if(tmp == 3)
                {
                    ans ++;
                }
            }
            if(i < n && j > 1)
            {
                int tmp = a[i][j] ^ a[i + 1][j] ^ a[i][j - 1];
                if(tmp == 3)
                {
                    ans ++;
                }
            }
            if(i > 1 && j > 1)
            {
                int tmp = a[i][j] ^ a[i - 1][j] ^ a[i][j - 1];
                if(tmp == 3)
                {
                    ans ++;
                }
            }
        }
    }
    cout << ans << endl;
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
    return 0;
}