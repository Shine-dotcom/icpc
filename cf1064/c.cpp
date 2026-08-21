#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        if(a[i] > mx)
        {
            mx = a[i];
        }
    }
    int res = 0;
    for(int i = 1; i < n; i ++ )
    {
        res += max(a[i], a[i + 1]);
    }
    res += max(a[1], a[n]);
    res -= mx;
    cout << res << endl;
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
}