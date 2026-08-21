#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<double> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i ++ )
    {
        a[i + 1] = sqrt(a[i] * a[i + 1]);
    }
    cout << fixed << setprecision(9) << a[n] << endl;
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