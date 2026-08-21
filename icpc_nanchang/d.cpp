#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int x, y, z;
};
void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<node> st(n + 1), ed(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> st[i].x >> st[i].y >> st[i].z;
        cin >> ed[i].x >> ed[i].y >> ed[i].z;
    }
    vector<pair<int, int>> x0(n + 1), y0(n + 1), z0(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        x0[i].first = min(st[i].x, ed[i].x);
        x0[i].second = max(st[i].x, ed[i].x);
        y0[i].first = min(st[i].y, ed[i].y);
        y0[i].second = max(st[i].y, ed[i].y);
        z0[i].first = min(st[i].z, ed[i].z);
        z0[i].second = max(st[i].z, ed[i].z);
    }
    sort(x0.begin() + 1, x0.end());
    sort(y0.begin() + 1, y0.end());
    sort(z0.begin() + 1, z0.end());
    vector<int> prex(n + 1), prey(n + 1), prez(n + 1);
    for(auto &[x, y] : x0)
    {
        prex[x] += 1;
        if(y != a)
        prex[y + 1] -= 1;
    }
    for(auto &[x, y] : y0)
    {
        prey[x] += 1;
        prey[y + 1] -= 1;
    }
    for(auto &[x, y] : z0)
    {
        prez[x] += 1;
        prez[y + 1] -= 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        prex[i] += prex[i - 1];
        prey[i] += prey[i - 1];
        prez[i] += prez[i - 1];
        ans = max(ans, prex[i]);
        ans = max(ans, prey[i]);
        ans = max(ans, prez[i]);
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
    return 0;
}