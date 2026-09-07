#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 5e5 + 10;
int a[N], c[N];
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
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) c[i] = a[i] - a[i - lowbit(i)];
    // for(int i = 1; i <= n; i ++ ) cout << c[i] << ' ';
    // cout << endl;
    while(m -- )
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k, n);
            add(y + 1, -k, n);
        }
        if(op == 2)
        {
            int x;
            cin >> x;
            cout << query(x) << endl;
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