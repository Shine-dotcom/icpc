#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, tr_l[100005], tr_r[100005];
int lowbit(int x)
{
    return x & (-x);
}
void add_l(int x, int v)
{
    while(x <= n)
    {
        tr_l[x] += v;
        x += lowbit(x);
    }
}
void add_r(int x, int v)
{
    while(x <= n)
    {
        tr_r[x] += v;
        x += lowbit(x);
    }
}
int suml(int x)
{
    int res = 0;
    while(x)
    {
        res += tr_l[x];
        x -= lowbit(x);
    }
    return res;
}
int sumr(int x)
{
    int res = 0;
    while(x)
    {
        res += tr_r[x];
        x -= lowbit(x);
    }
    return res;
}
void solve()
{
    int m;
    cin >> n >> m;
    while(m -- )
    {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1)
        {
            add_l(l, 1);
            add_r(r, 1);
        }
        if(op == 2)
        {
            cout << suml(r) - sumr(l - 1) << endl;
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