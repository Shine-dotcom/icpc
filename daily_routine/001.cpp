#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<double> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i] >> b[i] >> c[i];
    auto f = [&](double x) -> double {
        double res = -1e18;
        for(int i = 1; i <= n; i ++ )
        {
            res = max(res, a[i] * x * x + b[i] * x + c[i]);
        }
        return res;
    };
    double l = 0, r = 1000;
    while(r - l > 1e-6)
    {
        double mid1 = (2 * l + r) / 3;
        double mid2 = (l + 2 * r) / 3;
        if(f(mid1) > f(mid2)) l = mid1;
        else r = mid2;
    }
    cout << fixed << setprecision(4) << f(l) << endl;
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