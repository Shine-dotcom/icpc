#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> q(n + 1), r(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> q[i];
        q[i] ++;
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> r[i];
        r[i] ++;
    }
    sort(r.begin() + 1, r.end());
    sort(q.begin() + 1, q.end());
    // for(auto x : q) cout << x << ' ';
    // cout << endl;
    // for(auto x : r) cout << x << ' ';
    // cout << endl;
    int r0 = n;
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
    {
        int ll = 1, rr = r0;
        while(ll < rr)
        {
            int mid = (ll + rr + 1) >> 1;
            if((q[i]) * (r[mid]) <= k + 1) ll = mid;
            else rr = mid - 1;
        }
        // cout << "r: ";
        // cout << rr << endl;
        if((q[i]) * (r[ll]) > k + 1) break;
        if(r0 <= 0) break;
        r0 = rr - 1;
        ans ++;
    }
    // cout << endl;
    // cout << "ans:" << endl;
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