#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    int x = n - 2 - k;
    int cnt1 = n / 2;
    int cnt0 = n - cnt1;
    if(x < 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n + 1, 1);
    if(x % 2)
    {
        ans[n] = 0;
        cnt0 --;
    }
    for(int i = 2 - (x % 2 == 0); i <= x; i += 2)
    {
        ans[n - i] = 0;
        cnt0 --;
    }
    for(int i = 1; i <= cnt0; i ++ )
    {
        ans[i] = 0;
    }
    for(int i = 1; i <= n; i ++ )
    {
        cout << ans[i];
    }
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
    return 0;
}