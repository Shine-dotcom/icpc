#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    int k = x;
    int ans = 0;
    vector<int> v(m + 1);
    while(n -- )
    {
        vector<int> now(m + 1);
        for(int i = 1; i <= m; i ++ )
        {
            cin >> now[i];
            if(now[i] > v[i])
            {
                k -= now[i] - v[i];
                v[i] = now[i];
            }
        }
        if(k < 0)
        {
            break;
        }
        ans ++;
    }
    cout << ans << endl;
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