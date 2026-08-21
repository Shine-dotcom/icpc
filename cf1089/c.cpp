#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(i == 1)
        {
            if(__gcd(a[i], a[i + 1]) < b[i])
            ans ++;
        }
        if(i > 1 && i < n)
        {
            int x = __gcd(a[i], a[i + 1]);
            int y = __gcd(a[i], a[i - 1]);
            if(x * y / __gcd(x, y) < b[i])
            ans ++;
        }
        if(i == n)
        {
            if(__gcd(a[i], a[i - 1]) < b[i])
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
}