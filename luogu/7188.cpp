#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int tr[100005];
int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int v)
{
    while(x <= 100000)
    {
        tr[x] += v;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int res = 0;
    while(x)
    {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    while(n -- )
    {
        int l, r;
        cin >> l >> r;
        int L = sum(l), R = sum(r);
        cout << L + R << endl;
        add(l + 1, 1), add(r, -1);
        add(l, -L), add(l + 1, L);
        add(r, -R), add(r + 1, R);
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