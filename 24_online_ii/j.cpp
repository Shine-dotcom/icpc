#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct goods{
    int w, v, c;
    bool operator < (const goods &u) const {
        if(w == u.w) return c > u.c;
        return w < u.w;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<goods> g(n + 1);
    int sumv = 0, sumw = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> g[i].w >> g[i].v >> g[i].c;
        sumv += g[i].v;
        sumw += g[i].w;
    }
    sort(g.begin() + 1, g.end());
    int val1 = sumv;
    int w0 = sumw;
    for(int i = 1; i <= n; i ++ )
    {
        w0 -= g[i].w;
        val1 -= g[i].c * w0;
    }
    sort(g.begin() + 1, g.end(), [&](goods x, goods y) {
        return (x.c == y.c ? x.w < y.w : x.c > y.c);
    });
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << g[i].w << ' ' << g[i].v << ' ' << g[i].c << endl;
    // }
    int val2 = sumv;
    w0 = sumw;
    for(int i = 1; i <= n; i ++ )
    {
        w0 -= g[i].w;
        val2 -= g[i].c * w0;
    }
    cout << min(val1, val2) << endl;
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