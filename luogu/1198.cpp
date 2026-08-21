#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n = 0, tr[800005];
const int inf = (1ll << 62);
void update(int pos, int k, int p, int s, int e, int mod)
{
    if(s == e)
    {
        tr[p] = k % mod;
        return;
    }
    int mid = (s + e) >> 1;
    if(pos <= mid) update(pos, k, p << 1, s, mid, mod);
    else update(pos, k, p << 1 | 1, mid + 1, e, mod);
    tr[p] = max(tr[p << 1], tr[p << 1 | 1]) % mod;
}
int getres(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr[p];
    }
    int mid = (s + e) >> 1;
    int res = -inf;
    if(l <= mid) res = max(res, getres(l, r, p << 1, s, mid));
    if(r > mid) res = max(res, getres(l, r, p << 1 | 1, mid + 1, e));
    return res;
}
void solve()
{
    int m, mod;
    cin >> m >> mod;
    int t = 0;
    for(int i = 1; i <= m; i ++ )
    {
        char op;
        int s;
        cin >> op >> s;
        if(op == 'A')
        {
            update(n + 1, (s + t) % mod, 1, 1, m, mod);
            n ++;
        }
        if(op == 'Q')
        {
            if(s == 0) t = 0;
            else t = getres(n - s + 1, n, 1, 1, m);
            cout << t << endl;
        }
    }
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