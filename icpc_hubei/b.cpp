#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct point {
    int x, y;
};
void solve()
{
    // cout << distance(1, 1, 0, 0) << endl;
    // cout << sqrt((double)0) << endl;
    int n;
    cin >> n;
    vector<point> s(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> s[i].x >> s[i].y;
    }
    double ans = 1e9;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = i + 1; j <= n; j ++ )
        {
            for(int k = j + 1; k <= n; k ++ )
            {
                // cout << i << ' ' << j << ' ' << k << endl;
                point a = {s[i].x - s[j].x, s[i].y - s[j].y};
                point b = {s[i].x - s[k].x, s[i].y - s[k].y};
                int res = abs(a.x * b.y - a.y * b.x);
                // if(ans >= helen(a, b, c))
                // {
                //     cout << s[i].x << ' ' << s[i].y << endl;
                //     cout << s[j].x << ' ' << s[j].y << endl;
                //     cout << s[k].x << ' ' << s[k].y << endl;
                // }
                // cout << endl;
                if(res == 0) continue;
                // double p = (a + b + c) / 2;
                // cout << p << ' ' << (p - a) << ' ' << (p - b) << ' ' << (p - c) << endl;
                ans = min(ans, double(res) / 2);
                // cout << helen(a, b, c) << endl;
            }
        }
    }
    if(abs(ans - 1e9) <= 1e-6)
    {
        cout << -1 << endl;
        return;
    }
    cout << fixed << setprecision(14) << ans << endl;
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