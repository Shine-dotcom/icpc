#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, q;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int mx = 0, mn = 1e18;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i] != b[i])
        {
            mx = max(a[i], mx);
            mn = min(a[i], mn);
        }
        cout << b[i] << ' ';
    }
    cout << endl;
    // while(q -- )
    // {
    //     int x;
    //     cin >> x;
    //     if(mx == 0)
    //     {
    //         cout << "Yes" << endl;
    //     }
    //     else if(x <= mx * mn)
    //     {
    //         cout << "Yes" << endl;
    //     }
    //     else
    //     {
    //         cout << "No" << endl;
    //     }
    // }
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