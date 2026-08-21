#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), lis1(n + 1), lis2(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        lis1[i] = 1;
        for(int j = 1; j < i; j ++ )
        {
            if(a[i] > a[j]) lis1[i] = max(lis1[i], lis1[j] + 1);
        }
        // cout << lis1[i] << ' ';
    }
    // cout << endl;
    for(int i = n; i >= 1; i -- )
    {
        lis2[i] = 1;
        for(int j = n; j > i; j -- )
        {
            if(a[i] > a[j]) lis2[i] = max(lis2[i], lis2[j] + 1);
        }
    }
    // for(int i = 1; i <= n; i ++ ) cout << lis2[i] << ' ';
    // cout << endl;
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        ans = max(ans, lis1[i] + lis2[i] - 1);
    }
    cout << n - ans << endl;
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