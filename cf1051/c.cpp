#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int u, v, st;
};
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> tmp(n)
    for(int i = 0; i < n; i ++ )
    {
        p[i] = i + 1;
        tmp[i] = i + 1;
    }
    vector<vector<node>> a(n + 1);
    for(int i = 0; i < n - 1; i ++ )
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        a[u].push_back({v, (x > y)});
        a[v].push_back({u, (y > x)});
    }
    
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
}