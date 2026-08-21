#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    vector<int> pre(n + 1, 1e9), suf(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        pre[i] = min(pre[i - 1], a[i]);
    }
    suf[n] = a[n];
    for(int i = n - 1; i >= 1; i -- )
    {
        suf[i] = max(suf[i + 1], a[i]);
    }
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << pre[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << suf[i] << ' ';
    // }
    // cout << endl;
    for(int i = 1; i < n; i ++ )
    {
        if(pre[i] >= suf[i + 1]) 
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}