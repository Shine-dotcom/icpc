#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int SZ = 150000;
int n, m, sqn, c[SZ], ct[SZ], c1, c2, mem[SZ][3], ans, tot[1000005], nal[SZ];

struct query{
    int l, r, i, c;

    bool operator < (const query &u) const {
        if(l / sqn == u.l / sqn)
        {
            if(r / sqn == u.r / sqn) return i < u.i;
            return r < u.r;
        }
        return l < u.l;
    }
} Q[SZ];

void add(int a)
{
    if (!tot[a]) ans ++;
    tot[a] ++;
}

void del(int a)
{
    tot[a] --;
    if(!tot[a]) ans --;
}

char opt;

void solve()
{
    cin >> n >> m;
    sqn = pow(n, (double)2 / (double)3);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> c[i];
        ct[i] = c[i];
    }
    for(int i = 1, a, b; i <= m; i ++ )
    {
        cin >> opt >> a >> b;
        if(opt == 'Q')
        {
            Q[c1].l = a, Q[c1].r = b, Q[c1].i = c1, Q[c1].c = c2, c1 ++;
        }
        else
        {
            mem[c2][0] = a, mem[c2][1] = ct[a], mem[c2][2] = ct[a] = b, c2 ++;
        }
    }
    sort(Q, Q + c1), add(c[1]);
    int l = 1, r = 1, lst = 0;
    for(int i = 0; i < c1; i ++ )
    {
        for(; lst < Q[i].c; lst ++)
        {
            if(l <= mem[lst][0] && mem[lst][0] <= r)
            {
                del(mem[lst][1]), add(mem[lst][2]);
            }
            c[mem[lst][0]] = mem[lst][2];
        }
        for(; lst > Q[i].c; lst --)
        {
            if(l <= mem[lst - 1][0] && mem[lst - 1][0] <= r)
            {
                del(mem[lst - 1][2]), add(mem[lst - 1][1]);
            }
            c[mem[lst - 1][0]] = mem[lst - 1][1];
        }
        while(l > Q[i].l) add(c[--l]);
        while(r < Q[i].r) add(c[++r]);
        while(l < Q[i].l) del(c[l++]);
        while(r > Q[i].r) del(c[r--]);
        nal[Q[i].i] = ans;
    }
    for(int i = 0; i < c1; i ++ ) cout << nal[i] << endl;
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