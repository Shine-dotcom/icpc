#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int fa[20 * N], f[20][N];
const int mod = 1e9 + 7;
int n;
int qpow(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int fath(int x)
{
    return fa[x] = (fa[x] == x ? x : fath(fa[x]));
}
void dtr(int v, int& y)
{
    v %= n;
    y = (v ? v : n);
}
void u(int x, int y)
{
    x = fath(x);
    y = fath(y);
    if(x != y)
    {
        fa[x] = y;
    }
}
void solve()
{
    int m;
    cin >> n >> m;
    int ctt = 0;
    for(int i = 0; i < 20; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            f[i][j] = ++ ctt;
        }
    }
    for(int i = 1; i <= ctt; i ++ ) fa[i] = i;
    int ln = log2(n);
    while(m -- )
    {
        int l, r, len, d;
        cin >> l >> r >> len >> d;
        d = len - l;
        len = r - l + 1;
        for(int k = 0; len ; len >>= 1, k ++ )
        {
            if(len & 1)
            {
                int p1 = l + ((len >> 1) << (k + 1));
                int p2 = p1 + d;
                // cout << p1 << ' ' << p2 << endl;
                u(f[k][p1], f[k][p2]);
            }
        }
    }
    for(int i = ln; i > 0; i -- )
    {
        for(int j = 1; j + (1 << i) - 1 <= n; j ++ )
        {
            int father = fath(f[i][j]);
            if(father == f[i][j]) continue;
            int y; dtr(father, y);
            // cout << j << ' ' << j + (1 << (i - 1)) << ' ' << father << endl;
            u(f[i - 1][j], f[i - 1][y]);
            u(f[i - 1][j + (1 << (i - 1))], f[i - 1][y + (1 << (i - 1))]);
        }
    }
    set<int> res;
    for(int i = 1; i <= n; i ++ )
    {
        res.insert(fath(f[0][i]));
        // cout << fath(f[0][i]) << ' ';
    }
    // cout << endl;
    int sz = res.size();
    // cout << sz << endl;
    cout << (9 * qpow(10, sz - 1)) % mod << endl;
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