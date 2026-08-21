#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int sum = 0;
void build(vector<int> &tr, vector<int> &a, int l, int r, int p)
{
    if(l == r)
    {
        tr[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(tr, a, l, mid, p << 1);
    build(tr, a, mid + 1, r, p << 1 | 1);
    tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
}
void update(vector<int> &tr, int l, int r, int p, int s, int e)
{
    if(tr[p] <= 2) return;
    if(s == e)
    {
        sum -= (tr[p] - (int)(log2(tr[p]) + 1));
        tr[p] = (int)(log2(tr[p]) + 1);
        return;
    }
    int mid = (s + e) >> 1;
    if(l <= mid) update(tr, l, r, p << 1, s, mid);
    if(r > mid) update(tr, l, r, p << 1 | 1, mid + 1, e);
    tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), tr(n << 2);
    sum = 0;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];
    build(tr, a, 1, n, 1);
    while(m -- )
    {
        int l, r;
        cin >> l >> r;
        update(tr, l, r, 1, 1, n);
        cout << sum << endl;
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