#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> q(m);
    for(int i = 0; i < m; i ++ )
    {
        cin >> q[i].first >> q[i].second;
    }
    sort(q.begin(), q.end());
    vector<pair<int, int>> q1;
    for(int i = 0; i < m; i ++ )
    {
        int l = q[i].first, r = q[i].second;
        while(i < m - 1 && q[i + 1].first <= r) r = q[i + 1].second, i ++ ;
        q1.push_back({l, r});
    }
    // for(auto x : q1)
    // {
    //     cout << x.first << ' ' << x.second << endl;
    // }
    vector<int> a(k + 1);
    for(int i = 1; i <= k; i ++ )
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = 0;
    for(auto x : q1)
    {
        int l0 = x.first, r0 = x.second, l1, r1;
        cin >> l0 >> r0;
        int l = 1, r = k;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(a[mid] <= l0) l = mid;
            else r = mid - 1;
            // cout << "222: " << l << ' ' << r << endl;
        }
        l1 = a[l];
        l = 1, r = k;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(a[mid] >= r0) r = mid;
            else l = mid + 1;
            // cout << "111: " << l << ' ' << r << endl;
        }
        r1 = a[l];
        ans += (r1 - l1);
        // cout << l1 << ' ' << r1 << endl;
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