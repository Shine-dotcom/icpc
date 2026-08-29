#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        res ^= x;
    }
    cout << (res == 0 ? "No" : "Yes") << endl;
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