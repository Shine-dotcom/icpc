#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int f[45][45][45][45];
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1], b[m + 1];
    int g[5];
    memset(g, 0, sizeof(g));
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    f[0][0][0][0] = a[1];
    for(int i = 1; i <= m; i ++ )
    {
        cin >> b[i];
        g[b[i]] ++;
    }
    // for(int i = 1; i <= 4; i ++ ) cout << g[i] << ' ';
    for(int x = 0; x <= g[1]; x ++ )
        for(int y = 0; y <= g[2]; y ++ )
            for(int z = 0; z <= g[3]; z ++ )
                for(int w = 0; w <= g[4]; w ++ )
                {
                    if(x > 0) f[x][y][z][w] = max(f[x - 1][y][z][w] + a[x + 2 * y + 3 * z + 4 * w + 1], f[x][y][z][w]);
                    if(y > 0) f[x][y][z][w] = max(f[x][y - 1][z][w] + a[x + 2 * y + 3 * z + 4 * w + 1], f[x][y][z][w]);
                    if(z > 0) f[x][y][z][w] = max(f[x][y][z - 1][w] + a[x + 2 * y + 3 * z + 4 * w + 1], f[x][y][z][w]);
                    if(w > 0) f[x][y][z][w] = max(f[x][y][z][w - 1] + a[x + 2 * y + 3 * z + 4 * w + 1], f[x][y][z][w]);
                }
    cout << f[g[1]][g[2]][g[3]][g[4]] << endl;
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