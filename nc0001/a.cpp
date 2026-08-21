#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    vector<double> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if(a[0] + a[1] <= a[2])
    {
        cout << "wtnl" << endl;
        return;
    }
    cout << "Yes" << endl;
    vector<double> res(3);
    res[0] = (a[0] + a[1] - a[2]) / 2;
    res[1] = a[0] - res[0];
    res[2] = a[1] - res[0];
    sort(res.begin(), res.end());
    cout << fixed << setprecision(2) << res[0] << ' ' << res[1] << ' ' << res[2] << endl;
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