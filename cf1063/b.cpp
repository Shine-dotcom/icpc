#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), idx(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        idx[a[i]] = i;
    }
    string x;
    cin >> x;
    x = " " + x;
    if(x[1] == '1' || x[n] == '1')
    {
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= n; i ++ )
    {
        if((a[i] == 1 || a[i] == n) && x[i] == '1')
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << 5 << endl;
    cout << min(idx[1], 1ll) << ' ' << max(idx[1], 1ll) << endl;
    cout << min(idx[n], 1ll) << ' ' << max(idx[n], 1ll) << endl;
    cout << min(idx[1], n) << ' ' << max(idx[1], n) << endl;
    cout << min(idx[n], n) << ' ' << max(idx[n], n) << endl;
    cout << min(idx[n], idx[1]) << ' ' << max(idx[n], idx[1]) << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t -- )
    {
        solve();
    }
}