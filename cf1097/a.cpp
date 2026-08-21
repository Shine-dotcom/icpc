#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = n - 1; i >= 1; i -- ) a[i] = max(a[i], a[i] + a[i + 1]);
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i] > 0)
        {
            ans ++;
        }
    }
    cout << ans << endl;
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