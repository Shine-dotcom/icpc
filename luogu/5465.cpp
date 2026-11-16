#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 3e5 + 10;
int l[N], f[N][25], g[N][25];
int get(int x, int to)
{
    if(l[x] <= to) return x - to;
    int ans = x - l[x], tot = 1;
    x = l[x];
    for(int i = 20; i >= 0; i -- )
    {
        if(f[x][i] >= to)
        {
            ans += tot * (x - f[x][i]) + g[x][i];
            tot += (1 << i);
            x = f[x][i];
        }
    }
    if(x > to) ans += tot * (x - to) + x - to;
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 0; j <= 20; j ++ )
        {
            f[i][j] = 0;
            g[i][j] = 0;
        }
    }
    for(int i = 2; i <= n; i ++ )
    {
        cin >> l[i];
    }
    f[n + 1][0] = n + 1;
    for(int i = n; i >= 1; i -- )
    {
        f[i][0] = min(f[i + 1][0], l[i]);
        g[i][0] = i - f[i][0];
    }
    int k = 20;
    for(int i = 1; i <= k; i ++ )
    {
        for(int j = 2; j <= n; j ++ )
        {
            f[j][i] = f[f[j][i - 1]][i - 1];
            g[j][i] = g[j][i - 1] + g[f[j][i - 1]][i - 1] + (1 << (i - 1)) * (f[j][i - 1] - f[j][i]);
        }
    }
    int q;
    cin >> q;
    while(q -- )
    {
        int li, ri, xi;
        cin >> li >> ri >> xi;
        int up = get(xi, li) - get(xi, ri + 1);
        int down = ri - li + 1;
        int gcd = __gcd(up, down);
        up /= gcd;
        down /= gcd;
        cout << up << '/' << down << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- ) solve();
    return 0;
}