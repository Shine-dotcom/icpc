#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node {
    int v, i;
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<node> a(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i].v;
        a[i].i = i;
        sum += a[i].v;
    }
    int o = 0, e = 0;
    for(int i = 1; i <= m; i ++ )
    {
        int x;
        cin >> x;
        if(x % 2) o ++;
        else e ++;
    }
    // cout << "o: " << o << endl;
    // cout << "e: " << e << endl;
    sort(a.begin() + 1, a.end(), [&](node x, node y){
        return x.v > y.v;
    });
    int o0 = o, e0 = e;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i].i % 2 && o0 && a[i].v >= 0)
        {
            o0 --;
            sum -= a[i].v;
        }
        if(a[i].i % 2 == 0 && e0 && a[i].v >= 0)
        {
            e0 --;
            sum -= a[i].v;
        }
    }
    if(e == e0 && e)
    {
        for(int i = 1; i <= n; i ++ )
        {
            if(a[i].i % 2 == 0)
            {
                sum -= a[i].v;
                break;
            }
        }
    }
    if(o == o0 && o)
    {
        for(int i = 1; i <= n; i ++ )
        {
            if(a[i].i % 2)
            {
                sum -= a[i].v;
                break;
            }
        }
    }
    cout << sum << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}