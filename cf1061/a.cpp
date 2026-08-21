#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    while(n >= 3)
    {
        ans += n / 3;
        n = n / 3 + n % 3;
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