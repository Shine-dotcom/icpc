#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int mx = -1e9, mn = 1e9;
    for(int i = 0; i < n; i ++ )
    {
        int t;
        cin >> t;
        mx = max(t, mx);
        mn = min(t, mn);
    }
    int x;
    cin >> x;
    if(mn <= x && x <= mx)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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