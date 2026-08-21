#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    int m = n - k;
    for(int i = 1; i <= m; i ++ )
    {
        cout << 4;
    }
    for(int i = m + 1; i <= n; i ++ )
    {
        cout << 1;
    }
    cout << endl;
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