#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, a[100005], tr[270000], lz[270000], mul[270000];
void push_up(int p);
void build(int l, int r, int p)
{
    mul[p] = 1;
    if(l == r)
    {
        tr[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    push_up(p);
}
void push_up(int p)
{
    tr[p] = (tr[p << 1] + tr[p << 1 | 1]) % m;
}
void push_down(int l, int r, int p)
{
    if(lz[p] == 0 && mul[p] == 1) return;
    mul[p << 1] = (mul[p << 1] * mul[p]) % m;
    mul[p << 1 | 1] = (mul[p << 1 | 1] * mul[p]) % m;
    lz[p << 1] = (lz[p << 1] * mul[p] + lz[p]) % m;
    lz[p << 1 | 1] = (lz[p << 1 | 1] * mul[p] + lz[p]) % m;
    int mid = (l + r) >> 1;
    tr[p << 1] = (tr[p << 1] * mul[p] + (mid - l + 1) * lz[p]) % m;
    tr[p << 1 | 1] = (tr[p << 1 | 1] * mul[p] + (r - mid) * lz[p]) % m;
    lz[p] = 0, mul[p] = 1;
}
void add(int l, int r, int p, int s, int e, int c)
{
    if(l <= s && e <= r)
    {
        tr[p] = (tr[p] + (e - s + 1) * c) % m;
        lz[p] = (lz[p] + c) % m;
        return;
    }
    push_down(s, e, p);
    int mid = (s + e) >> 1;
    if(l <= mid) add(l, r, p << 1, s, mid, c);
    if(r > mid) add(l, r, p << 1 | 1, mid + 1, e, c);
    push_up(p);
}
int getsum(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr[p] % m;
    }
    push_down(s, e, p);
    int mid = (s + e) >> 1;
    int sum = 0;
    if(l <= mid) sum = (sum + getsum(l, r, p << 1, s, mid)) % m;
    if(r > mid) sum = (sum + getsum(l, r, p << 1 | 1, mid + 1, e)) % m;
    return sum % m;
}
void _mul(int l, int r, int p, int s, int e, int c)
{
    if(l <= s && e <= r)
    {
        tr[p] = (tr[p] * c) % m;
        lz[p] = (lz[p] * c) % m;
        mul[p] = (mul[p] * c) % m;
        return;
    }
    push_down(s, e, p);
    int mid = (s + e) >> 1;
    if(l <= mid) _mul(l, r, p << 1, s, mid, c);
    if(r > mid) _mul(l, r, p << 1 | 1, mid + 1, e, c);
    push_up(p);
}
void solve()
{
    int q;
    cin >> n >> q >> m;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    build(1, n, 1);
    while(q -- )
    {
        int op, x, y, k;
        cin >> op >> x >> y;
        if(op == 1)
        {
            cin >> k;
            _mul(x, y, 1, 1, n, k);
        }
        if(op == 2)
        {
            cin >> k;
            add(x, y, 1, 1, n, k);
        }
        if(op == 3)
        {
            cout << getsum(x, y, 1, 1, n) << endl;
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