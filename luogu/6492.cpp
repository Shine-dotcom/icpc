#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, tr[800005], l[800005], r[800005], s[800005], h[800005];
void work(int p, int k)
{
    tr[p] = s[p] = h[p] = 1;
    l[p] = r[p] = k;
}
void pushup(int st, int ed, int p)
{
    if(l[p << 1 | 1] != r[p << 1])
    {
        tr[p] = s[p << 1 | 1] + h[p << 1];
        tr[p] = max(tr[p << 1], tr[p]);
        tr[p] = max(tr[p << 1 | 1], tr[p]);
    }
    else tr[p] = max(tr[p << 1 | 1], tr[p << 1]);
    l[p] = l[p << 1], r[p] = r[p << 1 | 1];
    int mid = (st + ed) >> 1;
    if(s[p << 1] == (mid - st + 1) && l[p << 1 | 1] ^ r[p << 1]) s[p] = s[p << 1] + s[p << 1 | 1];
    else s[p] = s[p << 1];
    if(h[p << 1 | 1] == (ed - mid) && l[p << 1 | 1] ^ r[p << 1]) h[p] = h[p << 1] + h[p << 1 | 1];
    else h[p] = h[p << 1 | 1];
}
void build(int le, int ri, int p)
{
    if(le == ri)
    {
        work(p, 0);
        return;
    }
    int mid = (le + ri) >> 1;
    build(le, mid, p << 1);
    build(mid + 1, ri, p << 1 | 1);
    pushup(le, ri, p);
}
void update(int pos, int st, int ed, int p)
{
    if(st == ed)
    {
        work(p, !l[p]);
        return;
    }
    int mid = (st + ed) >> 1;
    if(pos <= mid) update(pos, st, mid, p << 1);
    else update(pos, mid + 1, ed, p << 1 | 1);
    pushup(st, ed, p);
}
void solve()
{
    int q;
    cin >> n >> q;
    build(1, n, 1);
    while(q -- )
    {
        int pos;
        cin >> pos;
        update(pos, 1, n, 1);
        // for(int i = 1; i <= 2 * n + 1; i ++ )
        // {
        //     cout << i << ' ' << tr[i] << ' ' << l[i] << ' ' << r[i] << endl;
        // }
        cout << tr[1] << endl;
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