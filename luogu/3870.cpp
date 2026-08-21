#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, tr[270000], lz[270000];
void push_down(int p, int l, int r)
{
    if(lz[p] == 0) return;
    lz[p << 1] ^= 1;
    lz[p << 1 | 1] ^= 1;
    int mid = l + ((r - l) >> 1);
    tr[p << 1] = (mid - l + 1) - tr[p << 1];
    tr[p << 1 | 1] = (r - mid) - tr[p << 1 | 1];
    lz[p] = 0;
}
void update(int l, int r, int s, int t, int p)
{
    // cout << l << ' ' << r << ' ' << s << ' ' << t << ' ' << p << endl;
    // cout << "111 " << lz[p] << endl;
    if(l <= s && t <= r)
    {
        tr[p] = (t - s + 1) - tr[p];
        lz[p] ^= 1;
        return;
    }
    push_down(p, s, t);
    int m = s + ((t - s) >> 1);
    // cout << "222 " << lz[p] << endl;
    if(l <= m) update(l, r, s, m, p << 1);
    if(r > m) update(l, r, m + 1, t, p << 1 | 1);
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
int getsum(int l, int r, int s, int t, int p)
{
    if(l <= s && t <= r)
    {
        return tr[p];
    }
    push_down(p, s, t);
    int m = s + ((t - s) >> 1);
    int sum = 0;
    if(l <= m) sum = getsum(l, r, s, m, p << 1);
    if(r > m) sum += getsum(l, r, m + 1, t, p << 1 | 1);
    return sum;
}
void solve()
{
    int m;
    cin >> n >> m;
    while(m -- )
    {
        int c, a, b;
        cin >> c >> a >> b;
        if(c == 0)
        {
            update(a, b, 1, n, 1);
        }
        if(c == 1)
        {
            cout << getsum(a, b, 1, n, 1) << endl;
        }
        // for(int i = 1; i <= 2 * n; i ++ )
        // {
        //     cout << i << ' ' << tr[i] << endl;
        // }
        // cout << endl;
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