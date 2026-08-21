#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, tr[800005];
bool lz[800005];
string s0;
void build(int l, int r, int p)
{
    if(l == r)
    {
        tr[p] = (s0[l] == '1');
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
void pushdown(int p, int l, int r)
{
    int mid = (l + r) >> 1;
    if(lz[p] == 0) return;
    lz[p << 1] ^= 1;
    lz[p << 1 | 1] ^= 1;
    tr[p << 1] = (mid - l + 1) - tr[p << 1];
    tr[p << 1 | 1] = (r - mid) - tr[p << 1 | 1];
    lz[p] = 0;
}
void update(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        tr[p] = (e - s + 1) - tr[p];
        lz[p] ^= 1;
        return;
    }
    pushdown(p, s, e);
    int mid = (s + e) >> 1;
    if(l <= mid) update(l, r, p << 1, s, mid);
    if(r > mid) update(l, r, p << 1 | 1, mid + 1, e);
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
int query(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr[p];
    }
    pushdown(p, s, e);
    int mid = (s + e) >> 1;
    int ans = 0;
    if(l <= mid) ans += query(l, r, p << 1, s, mid);
    if(r > mid) ans += query(l, r, p << 1 | 1, mid + 1, e);
    return ans;
}
void solve()
{
    int m;
    cin >> n >> m;
    cin >> s0;
    s0 = " " + s0;
    build(1, n, 1);
    while(m -- )
    {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 0)
        {
            update(l, r, 1, 1, n);
        }
        if(op == 1)
        {
            cout << query(l, r, 1, 1, n) << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
}