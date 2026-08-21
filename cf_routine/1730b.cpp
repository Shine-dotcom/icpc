#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> x(n + 1), t(n + 1);
    int mx = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> x[i];
        mx = max(x[i], mx);
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> t[i];
    }
    double l = 0, r = mx;
    auto check = [&](double x) -> bool {
        
    }
    while(l - r > 1e-10)
    {
        double mid = (l + r) / 2;

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
    return 0;
}