#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, a[500005];
struct Node{
    int maxl, maxr, sum, val;
}tr[1700005];
void pushup(Node &p, const Node &ls, const Node &rs)
{
    if(ls.maxr < 0 && rs.maxl < 0)
    {
        p.val = max(ls.maxr, rs.maxl);
    }
    else
    {
        p.val = 0;
        if(ls.maxr > 0)
            p.val += ls.maxr;
        if(rs.maxl > 0)
            p.val += rs.maxl;
    }
    p.val = max(p.val, ls.val);
    p.val = max(p.val, rs.val);
    p.maxl = max(ls.maxl, ls.sum + rs.maxl);
    p.maxr = max(rs.maxr, rs.sum + ls.maxr);
    p.sum = ls.sum + rs.sum;
}
void build(int l, int r, int p)
{
    if(l == r)
    {
        tr[p].val = tr[p].maxl = a[l];
        tr[p].maxr = tr[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
}
void update(int v, int p, int l, int r, int pp)
{
    if(l == r)
    {
        tr[p].val = tr[p].maxl = tr[p].maxr = tr[p].sum = v;
        return;
    }
    int mid = (l + r) >> 1;
    if(pp <= mid) update(v, p << 1, l, mid, pp);
    else update(v, p << 1 | 1, mid + 1, r, pp);
    pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
}
Node query(int s, int e, int p, int l, int r)
{
    if(l <= s && e <= r)
    {
        return tr[p];
    }
    int mid = (s + e) >> 1;
    if(l <= mid && mid < r)
    {
        Node res;
        pushup(res, query(s, mid, p << 1, l, r), query(mid + 1, e, p << 1 | 1, l, r));
        return res;
    }
    else if(l <= mid)
        return query(s, mid, p << 1, l, r);
    else
        return query(mid + 1, e, p << 1 | 1, l, r);
}
void solve()
{
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    build(1, n, 1);
    while(m -- )
    {
        int k;
        cin >> k;
        if(k == 1)
        {
            int a, b;
            cin >> a >> b;
            if(a > b) swap(a, b);
            cout << query(1, n, 1, a, b).val << endl;
        }
        if(k == 2)
        {
            int p, s;
            cin >> p >> s;
            update(s, 1, 1, n, p);
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