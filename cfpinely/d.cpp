#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= n; i ++ )
    {
        cout << a[i].first << ' ' << a[i].second << endl;
    }
    vector<int> dp(n + 1, 1);
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j < i; j ++ )
        {
            if(a[i].second < a[j].second || a[i].first != a[j].first + 1)
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << dp[i] << ' ';
    }
    cout << endl;
    cout << n - dp[n] << endl;
    cout << endl;
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