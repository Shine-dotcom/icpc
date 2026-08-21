#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 1; i <= n; i ++ )
    {
        if(c >= a[i])
        {
            int k0 = c - a[i];
            if(k0 <= k)
            {
                k -= k0;
                c *= 2;
            }
            else
            {
                c += a[i] + k;
                k = 0;
            }
        }
    }
    cout << c << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}
