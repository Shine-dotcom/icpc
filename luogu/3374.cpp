#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 5e5 + 10;
int a[N], c[N], pre[N];
int lowbit(int x) { return x & (-x); }
int query(int x)
{
    int res = 0;
    while(x > 0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
void add(int x, int k, int n)
{
    while(x <= n)
    {
        c[x] += k;
        x += lowbit(x);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    for(int i = 1; i <= n; i ++ ) c[i] = pre[i] - pre[i - lowbit(i)];
    // for(int i = 1; i <= n; i ++ ) cout << c[i] << ' ';
    // cout << endl;
    while(m -- )
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x, k;
            cin >> x >> k;
            add(x, k, n);
        }
        if(op == 2)
        {
            int x, y;
            cin >> x >> y;
            cout << query(y) - query(x - 1) << endl;
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