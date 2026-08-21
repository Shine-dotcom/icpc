#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m;
void dfs(int x, int y, int n, int m, vector<vector<int>> &a, vector<vector<int>> f)
{
    if(x > n || y > m || x <= 0 || y <= 0)
    {
        return;
    }
    if(x == n && y == m)
    {
        for(int i = 1; i <= n; i ++ )
        {
            for(int j = 1; j <= m; j ++ )
            {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    int x0[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int y0[] = {0, -1, -1, -1, 0, 1, 1, 1};
    for(int k = x; k <= n; k ++ )
    {
        for(int j = y; j <= m; j ++ )
        {
            bool flag1 = 0, flag2 = 0;
            for(int i = 0; i < 8; i ++ )
            {
                int a1 = 2, a2 = 2;
                if(k >= 2 * x0[i] && j >= 2 * y0[i]) a1 = a[k - 2 * x0[i]][j - 2 * y0[i]];
                if(k >= x0[i] && j >= y0[i]) a2 = a[k - x0[i]][j - y0[i]];
                if(a1 == 0 && a2 == 0) flag1 = 1;
                if(a1 == 1 && a2 == 1) flag2 = 1;
            }
            if(flag1 && flag2) return;
            if(!flag1 && !f[k][j])
            {
                f[k][j] = 1;
                a[k][j] = 0;
                for(int i = 0; i < 8; i ++ )
                {
                    dfs(x - x0[i], y - y0[i], n, m, a, f);
                }
                f[k][j] = 0;
                a[k][j] = 2;
            }
            if(!flag2 && !f[k][j])
            {
                f[k][j] = 1;
                a[k][j] = 1;
                for(int i = 0; i < 8; i ++ )
                {
                    dfs(x - x0[i], y - y0[i], n, m, a, f);
                }
                f[k][j] = 0;
                a[k][j] = 2;
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> (m + 1, 2)), f(n + 1, vector<int> (m + 1));
    dfs(1, 1, n, m, a, f);
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