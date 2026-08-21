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
    }
    for(int i = 1; i < n; i ++ )
    {
        mx = max(mx, a[i] - a[i + 1]);
    }
    for(int i = 1; i < n; i ++ )
    {
        if(a[i] > a[i + 1])
        {
            a[i + 1] += mx;
        }
    }
    for(int i = 1; i < n; i ++ )
    {
        if(a[i] > a[i + 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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