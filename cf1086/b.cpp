#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    vector<int> flag(n + 1);
    int ans = 0;
    int k0 = k;
    while(m > 0)
    {
        // cout << "m2: " << m << endl;
        int t = 0, mn = 1e9;
        for(int i = 1; i <= k0; i ++ )
        {
            if(a[i] < mn && !flag[i])
            {
                mn = a[i];
                t = i;
            }
        }
        if(k0 >= p)
        {
            ans ++;
            a.push_back(a[p]);
            flag[p] = 1;
            m -= a[p];
            p = (++ k0) + n - k;
            // cout << "p: " << p << endl;
            flag.push_back(0);
            continue;
        }
        a.push_back(a[t]);
        flag[t] = 1;
        k0 ++;
        m -= a[t];
        // cout << "t: " << t << endl;
        flag.push_back(0);
        // cout << "m: " << m << endl;
    }
    cout << ans << endl;
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