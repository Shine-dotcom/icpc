#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(l + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        a[x] ++;
    }
    vector<int> d(m + 1);
    for(int i = 1; i <= l; i ++ )
    {
        sort(d.begin() + 1, d.end(), greater<int>());
        int j = min(n + 1, m);
        d[j] ++;
        if(a[i])
        {
            sort(d.begin() + 1, d.end(), greater<int>());
            n --;
            d[1] = 0;
        }
    }
    int mx = 0;
    for(int i = 1; i <= m; i ++ )
    {
        mx = max(mx, d[i]);
    }
    cout << mx << endl;
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