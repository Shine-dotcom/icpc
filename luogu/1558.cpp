#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int maxn = 4e5 + 5;
int l, tr[maxn];
int lz[maxn];
void pushup(int p)
{
    tr[p] = tr[p << 1] | tr[p << 1 | 1];
}
void build(int l, int r, int p)
{
    if(l == r)
    {
        tr[p] = 2;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(l, mid, p << 1 | 1);
    pushup(p);
}
void pushdown(int p)
{
    if(lz[p] == 0) return;
    lz[p << 1] = lz[p << 1 | 1] = lz[p];
    tr[p << 1] = tr[p << 1 | 1] = lz[p];
    lz[p] = 0;
}
void update(int l, int r, int p, int s, int e, int c)
{
    if(l <= s && e <= r)
    {
        tr[p] = (1 << c);
        lz[p] = (1 << c);
        return;
    }
    pushdown(p);
    int mid = (s + e) >> 1;
    if(l <= mid) update(l, r, p << 1, s, mid, c);
    if(r > mid) update(l, r, p << 1 | 1, mid + 1, e, c);
    pushup(p);
}
int getres(int l, int r, int p, int s, int e)
{
    if(l <= s && e <= r)
    {
        return tr[p];
    }
    pushdown(p);
    int mid = (s + e) >> 1;
    int res = 0;
    if(l <= mid) res |= getres(l, r, p << 1, s, mid);
    if(r > mid) res |= getres(l, r, p << 1 | 1, mid + 1, e);
    return res;
}
void solve()
{
    int t, o;
    cin >> l >> t >> o;
    build(1, l, 1);
    while(o -- )
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(a > b) swap(a, b);
        if(c == 'C')
        {
            int k;
            cin >> k;
            update(a, b, 1, 1, l, k);
        }
        if(c == 'P')
        {
            int res = getres(a, b, 1, 1, l);
            int sum = 0;
            while(res)
            {
                sum += (res & 1);
                res >>= 1;
            }
            cout << sum << endl;
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