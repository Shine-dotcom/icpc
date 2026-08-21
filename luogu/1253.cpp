#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, a[1000005], tr[2700000], lz1[2700000], lz2[2700000], flag[2700000];
void build(int l, int r, int p)
{
    if(l == r)
    {
        tr[p] = a[l];
        return;
    }
    tr[p] = -1e18;
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
}
void push_down(int l, int r, int p)
{
    if(flag[p] == 1)
    {
        lz1[p << 1] = lz1[p];
        lz1[p << 1 | 1] = lz1[p];
        lz2[p << 1] = lz2[p];
        lz2[p << 1 | 1] = lz2[p];
        tr[p << 1] = lz1[p] + lz2[p];
        tr[p << 1 | 1] = lz1[p] + lz2[p];
        flag[p << 1] = flag[p << 1 | 1] = 1;
    }
    else
    {
        lz2[p << 1] += lz2[p];
        lz2[p << 1 | 1] += lz2[p];
        tr[p << 1] += lz2[p];
        tr[p << 1 | 1] += lz2[p];
    }
    flag[p] = lz1[p] = lz2[p] = 0;
}
void update1(int l, int r, int p, int s, int e, int c)
{
    if(l <= s && e <= r)
    {
        lz1[p] = c;
        lz2[p] = 0;
        tr[p] = c; // ?
        flag[p] = 1;
        return;
    }
    push_down(s, e, p);
    int mid = (s + e) >> 1;
    if(l <= mid) update1(l, r, p << 1, s, mid, c);
    if(r > mid) update1(l, r, p << 1 | 1, mid + 1, e, c);
    tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
}
void update2(int l, int r, int p, int s, int e, int c)
{
    if(l <= s && e <= r)
    {
        tr[p] += c;
        lz2[p] += c;
        return;
    }
    push_down(s, e, p);
    int mid = (s + e) >> 1;
    if(l <= mid) update2(l, r, p << 1, s, mid, c);
    if(r > mid) update2(l, r, p << 1 | 1, mid + 1, e, c);
    tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
}
int getsum(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr[p];
    }
    push_down(s, e, p);
    int mid = (s + e) >> 1;
    int res = -1e18;
    if(l <= mid) res = max(res, getsum(l, r, p << 1, s, mid));
    if(r > mid) res = max(res, getsum(l, r, p << 1 | 1, mid + 1, e));
    return res;
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
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1)
        {
            int x;
            cin >> x;
            update1(l, r, 1, 1, n, x);
        }
        if(op == 2)
        {
            int x;
            cin >> x;
            update2(l, r, 1, 1, n, x);
        }
        if(op == 3)
        {
            cout << getsum(l, r, 1, 1, n) << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    // clock_t start = clock();
    while(t -- )
    {
        solve();
    }
    // clock_t end = clock();
    // double time = (double)(end - start) / CLOCKS_PER_SEC;
    // time *= 1000;
    // cout << time << "ms" << endl;
    return 0;
}