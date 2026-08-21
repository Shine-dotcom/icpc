#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    vector<vector<int>> flag(n + 1, vector<int> (m + 1, 0));
    flag[1][1] = 1;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    int st = 2;
    auto dfs = [&](auto self, int i, int j) -> void {
        if(i < n && a[i + 1][j] == '.' && flag[i + 1][j] == 0)
        {
            st = max(st, i + 1 + j);
            flag[i + 1][j] = 1;
            self(self, i + 1, j);
        }
        if(i > 1 && a[i - 1][j] == '.' && flag[i - 1][j] == 0)
        {
            st = max(st, i - 1 + j);
            flag[i - 1][j] = 1;
            self(self, i - 1, j);
        }
        if(j < m && a[i][j + 1] == '.' && flag[i][j + 1] == 0)
        {
            st = max(st, i + 1 + j);
            flag[i][j + 1] = 1;
            self(self, i, j + 1);
        }
        if(j > 1 && a[i][j - 1] == '.' && flag[i][j - 1] == 0)
        {
            st = max(st, i - 1 + j);
            flag[i][j - 1] = 1;
            self(self, i, j - 1);
        }
    };
    dfs(dfs, 1, 1);
    int st0 = st;
    // cout << st << endl;
    if(st == n + m)
    {
        cout << 0 << endl;
        return;
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            flag[i][j] = 0;
        }
    }
    st = n + m;
    auto dfs2 = [&](auto self, int i, int j) -> void {
        if(i < n && a[i + 1][j] == '.' && flag[i + 1][j] == 0)
        {
            st = min(st, i + 1 + j);
            flag[i + 1][j] = 1;
            self(self, i + 1, j);
        }
        if(i > 1 && a[i - 1][j] == '.' && flag[i - 1][j] == 0)
        {
            st = min(st, i - 1 + j);
            flag[i - 1][j] = 1;
            self(self, i - 1, j);
        }
        if(j < m && a[i][j + 1] == '.' && flag[i][j + 1] == 0)
        {
            st = min(st, i + 1 + j);
            flag[i][j + 1] = 1;
            self(self, i, j + 1);
        }
        if(j > 1 && a[i][j - 1] == '.' && flag[i][j - 1] == 0)
        {
            st = min(st, i - 1 + j);
            flag[i][j - 1] = 1;
            self(self, i, j - 1);
        }
    };
    dfs2(dfs2, n, m);
    int ed0 = st;
    cout << ed0 - st0 - 1 << endl;
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
    return 0;
}