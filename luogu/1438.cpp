#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, raw[100005], a[100005], tr[270000], lz[270000];
void build(int l, int r, int p)
{
    if(l == r)
    {
        tr[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    tr[p] = tr[p << 1] + tr[(p << 1) | 1];
}
void push_down(int l, int r, int p)
{
    if(lz[p] == 0) return;
    int mid = (l + r) >> 1;
    tr[p << 1] += (mid - l + 1) * lz[p];
    tr[p << 1 | 1] += (r - mid) * lz[p];
    lz[p << 1] += lz[p], lz[p << 1 | 1] += lz[p];
    lz[p] = 0;
}
void update(int l, int r, int p, int s, int e, int c)
{
    if(l <= s && e <= r)
    {
        tr[p] += (e - s + 1) * c;
        lz[p] += c;
        return;
    }
    int mid = (s + e) >> 1;
    push_down(s, e, p);
    if(l <= mid) update(l, r, p << 1, s, mid, c);
    if(r > mid) update(l, r, p << 1 | 1, mid + 1, e, c);
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
int getsum(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr[p];
    }
    int mid = (s + e) >> 1;
    push_down(s, e, p);
    int sum = 0;
    if(l <= mid) sum = getsum(l, r, p << 1, s, mid);
    if(r > mid) sum += getsum(l, r, p << 1 | 1, mid + 1, e);
    return sum;
}
void solve()
{
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> raw[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        a[i] = raw[i] - raw[i - 1];
    }
    build(1, n, 1);
    while(m -- )
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            update(l, l, 1, 1, n, k);
            if(l + 1 <= r) update(l + 1, r, 1, 1, n, d);
            if(r < n)
            {
                update(r + 1, r + 1, 1, 1, n, -(k + (r - l) * d));
            }
        }
        if(op == 2)
        {
            if(n == 0)
            {
                cout << 0 << endl;
                continue;
            }
            int q;
            cin >> q;
            cout << getsum(1, q, 1, 1, n) << endl;
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