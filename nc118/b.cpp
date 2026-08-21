#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i].first >> a[i].second;
    }
    if(n == 1)
    {
        cout << a[1].first << ' ' << a[1].second << ' ';
        cout << a[1].first << ' ' << a[1].second << endl;
        return;
    }
    pair<int, int> x, y;
    double dis = -1;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            int t1 = a[i].first - a[j].first;
            int t2 = a[i].second - a[j].second;
            if(dis < t1 * t1 + t2 * t2)
            {
                x = a[i], y = a[j];
                dis = t1 * t1 + t2 * t2;
            }
        }
    }
    cout << x.first << ' ' << x.second << ' ' << y.first << ' ' << y.second << endl;
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
