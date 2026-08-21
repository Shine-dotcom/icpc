#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    vector<pair<int, int>> b(m + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i = 1; i <= m; i ++ )
    {
        cin >> b[i].first;
    }
    for(int i = 1; i <= m; i ++ )
    {
        cin >> b[i].second;
    }
    sort(b.begin() + 1, b.end(), [&](pair<int, int> x, pair<int, int> y){
        if((x.second == 0) ^ (y.second == 0)) return x.second > y.second;
        return x.first < y.first;
    });
    int ans = 0;
    // for(int i = 1; i <= m; i ++ )
    // {
    //     cout << b[i].first << ' ' << b[i].second << endl;
    // }
    // cout << endl;
    for(int i = 1; i <= m; i ++ )
    {
        auto it = a.lower_bound(b[i].first);
        if(it != a.end())
        {
            int t = *it;
            ans ++;
            a.erase(it);
            if(b[i].second)
            {
                a.insert(max(max(b[i].second, b[i].first), t));
            }
        }
    }
    cout << ans << endl;
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