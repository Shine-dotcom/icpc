#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int m;
    cin >> m;
    string s, t;
    cin >> s >> t;
    vector<int> a(m + 1);
    for(int i = 1; i <= m; i ++ )
    {
        a[i] = (int)(t[i - 1] - s[i - 1] + 26) % 26;
    }
    // for(int i = 1; i <= m; i ++ )
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    int ans = (a[1] != 0);
    for(int i = 1; i < m; i ++ )
    {
        if(a[i] != a[i + 1])
        {
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
    // cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}