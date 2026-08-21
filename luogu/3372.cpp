#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, a[100005], d[270000], b[270000];
void build(int l, int r, int p)
{
    if(l == r)
    {
        d[p] = a[l];
        return;
    }
    int m = l + ((r - l) >> 1);
    build(l, m, p << 1), build(m + 1, r, (p << 1 | 1));
    d[p] = d[p << 1] + d[(p << 1) | 1];
}

void update(int l, int r, int c, int s, int t, int p)
{
    if(l <= s && t <= r)
    {
        d[p] += (t - s + 1) * c, b[p] += c;
        return;
    }
    int m = s + ((t - s) >> 1);
    if(b[p])
    {
        d[p << 1] += b[p] * (m - s + 1);
        d[(p << 1) | 1] += b[p] * (t - m);
        b[p << 1] += b[p];
        b[(p << 1) | 1] += b[p];
    }
    b[p] = 0;
    if(l <= m)
    {
        update(l, r, c, s, m, p << 1);
    }
    if(r > m)
    {
        update(l, r, c, m + 1, t, (p << 1) | 1);
    }
    d[p] = d[p << 1] + d[(p << 1) | 1];
}

int getsum(int l, int r, int s, int t, int p) {
    if(l <= s && t <= r) return d[p];
    int m = s + ((t - s) >> 1);
    if(b[p])
    {
        d[p << 1] += b[p] * (m - s + 1);
        d[(p << 1) | 1] += b[p] * (t - m);
        b[p << 1] += b[p];
        b[(p << 1) | 1] += b[p];
    }
    b[p] = 0;
    int sum = 0;
    if(l <= m)
    {
        sum = getsum(l, r, s, m, p << 1);
    }
    if(r > m)
        sum += getsum(l, r, m + 1, t, (p << 1) | 1);
    return sum;
}
void solve()
{
    int q, i, x, y, k;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    build(1, n, 1);
    while(q -- )
    {
        cin >> i >> x >> y;
        if(i == 2)
        {
            cout << getsum(x, y, 1, n, 1) << endl;
        }
        if(i == 1)
        {
            cin >> k;
            update(x, y, k, 1, n, 1);
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