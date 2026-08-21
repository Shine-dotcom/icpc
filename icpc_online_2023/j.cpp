#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const double k = sqrt(2) / 2.0;
void solve()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    double a1 = (x1 + x2) / 2.0, b1 = (y1 + y2) / 2.0;
    double r1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 2.0;
    double a2 = (x3 + x4) / 2.0, b2 = (y3 + y4) / 2.0;
    double r2 = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4)) / 2.0;
    double ans = 1e9;
    ans = min(ans, abs(a2 + k * r2 - a1) + abs(b2 + k * r2 - b1));
    ans = min(ans, abs(a2 - k * r2 - a1) + abs(b2 + k * r2 - b1));
    ans = min(ans, abs(a2 + k * r2 - a1) + abs(b2 - k * r2 - b1));
    ans = min(ans, abs(a2 - k * r2 - a1) + abs(b2 - k * r2 - b1));
    cout << fixed << setprecision(12) << ans << endl;
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