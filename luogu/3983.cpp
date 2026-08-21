#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(11);
    for(int i = 1; i <= 10; i ++ )
    {
        cin >> a[i];
    }
    int c[11] = {0, 1, 3, 5, 7, 9, 10, 11, 14, 15, 17};
    vector<int> f(11);
    for(int i = 1; i <= 10; i ++ )
    {
        for(int j = i; j <= 10; j ++ )
        {
            f[j] = max(f[j], f[j - i] + a[i]);
        }
    }
    // for(auto x : f)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    vector<int> dp(n + 1);
    for(int i = 1; i <= 10; i ++ )
    {
        for(int j = i; j <= n; j ++ )
        {
            dp[j] = max(dp[j], dp[j - i] + f[i] - c[i]);
        }
        // for(int j = 0; j <= n; j ++ )
        // {
        //     cout << dp[j] << ' ';
        // }
        // cout << endl;
    }
    cout << dp[n] << endl;
    return 0;
}