#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
double a[100005], tr[270000], tr_sq[270000], lz[270000];
void pushup(int p)
{
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
    tr_sq[p] = tr_sq[p << 1] + tr_sq[p << 1 | 1];
}
void build(int l, int r, int p)
{
    if(l == r)
    {
        tr[p] = a[l];
        tr_sq[p] = a[l] * a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    pushup(p);
}
void pushdown(int l, int r, int p)
{
    if(lz[p] == 0) return;
    int mid = (l + r) >> 1;
    lz[p << 1] += lz[p];
    lz[p << 1 | 1] += lz[p];
    tr_sq[p << 1] += lz[p] * ((double)(mid - l + 1) * lz[p] + 2 * tr[p << 1]);
    tr_sq[p << 1 | 1] += lz[p] * ((double)(r - mid) * lz[p] + 2 * tr[p << 1 | 1]);
    tr[p << 1] += (double)(mid - l + 1) * lz[p];
    tr[p << 1 | 1] += (double)(r - mid) * lz[p];
    lz[p] = 0;
}
double query(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr[p];
    }
    pushdown(s, e, p);
    double sum = 0;
    int mid = (s + e) >> 1;
    if(l <= mid) sum += query(l, r, p << 1, s, mid);
    if(r > mid) sum += query(l, r, p << 1 | 1, mid + 1, e);
    return sum;
}
double query_sq(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr_sq[p];
    }
    pushdown(s, e, p);
    double sum = 0;
    int mid = (s + e) >> 1;
    if(l <= mid) sum += query_sq(l, r, p << 1, s, mid);
    if(r > mid) sum += query_sq(l, r, p << 1 | 1, mid + 1, e);
    return sum;
}
void update(int l, int r, int p, int s, int e, double c)
{
    if(l <= s && e <= r)
    {
        tr_sq[p] += 2 * c * tr[p] + (double)(e - s + 1) * c * c;
        tr[p] += (e - s + 1) * c;
        lz[p] += c;
        return;
    }
    pushdown(s, e, p);
    int mid = (s + e) >> 1;
    if(l <= mid) update(l, r, p << 1, s, mid, c);
    if(r > mid) update(l, r, p << 1 | 1, mid + 1, e, c);
    pushup(p);
}
void solve()
{
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    build(1, n, 1);
    // for(int i = 1; i <= 2 * n; i ++ )
    // {
    //     cout << i << ' ' << tr_sq[i] << endl;
    // }
    while(m -- )
    {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1)
        {
            double k;
            cin >> k;
            update(x, y, 1, 1, n, k);
        }
        if(op == 2)
        {
            cout << fixed << setprecision(4) << query(x, y, 1, 1, n) / (double)(y - x + 1) << endl;
        }
        if(op == 3)
        {
            double res = query(x, y, 1, 1, n) / (double)(y - x + 1);
            double tmp = query_sq(x, y, 1, 1, n) / (double)(y - x + 1);
            cout << fixed << setprecision(4) << tmp - res * res << endl;
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
    return 0;
}