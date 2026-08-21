#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> point(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        point[i] = {x, y};
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
        auto [x1, y1] = point[i];
        for(int j = i + 1; j <= n; j ++ )
        {
            auto [x2, y2] = point[j];
            int cnt_l = 0, cnt_r = 0;
            for(int k = 1; k <= n; k ++ )
            {
                auto [x, y] = point[k];
                if((x - x2) * (y1 - y2) > (x1 - x2) * (y - y2)) cnt_l ++;
                if((x - x2) * (y1 - y2) < (x1 - x2) * (y - y2)) cnt_r ++;
            }
            if(cnt_l == cnt_r) cnt ++;
        }
    }
    cout << cnt << endl;
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