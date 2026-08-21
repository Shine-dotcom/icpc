#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int w, s, t;
    bool operator < (const node &u) const{
        return t < u.t;
    }
};
struct node2{
    int idx, val;
};
int tr[100010];
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
    vector<node> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i].w >> a[i].s >> a[i].t;
    }
    sort(a.begin(), a.end());
    vector<node2> diff(n + 1);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        diff[i].val = a[i].s - a[i].w;
        diff[i].idx = i;
        pre[i] = pre[i - 1] + diff[i].val;
    }
    sort(diff.begin() + 1, diff.end(), [&](node2 x, node2 y){
        return x.val < y.val;
    });
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        add(i, a[i].s - a[i].w);
    }
    for(int i = 1; i <= n; i ++ )
    {
        // cout << "sum:" << endl;
        // cout << diff[i].idx << ' ' << sum(diff[i].idx) << endl;
        if(sum(n) < 0 || sum(diff[i].idx) < 0)
        {
            int j = diff[i].idx;
            ans ++;
            add(j, a[j].w - a[j].s);
        }
    }
    cout << ans << endl;
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