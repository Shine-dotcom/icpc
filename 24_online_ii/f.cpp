#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int val = 1500, n;
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        val += x;
        if(val >= 4000)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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
}