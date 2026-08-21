#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a[i].begin() + 1, a[i].end());
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = i + 1; j <= n; j ++ )
        {
            if(a[i].first == a[j].first && !((a[i].second + a[j].second) & 1))
            {
                int x = a[i].first;
                int y = (a[i].second + a[j].second) / 2;
                pair<int, int> node = {x, y};
                pair<int, int> tmp = *lower_bound(a.begin() + 1, a.end(), node);
                if(node)
            }
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