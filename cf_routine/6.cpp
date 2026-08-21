#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    vector<pair<int, int>> segs;
    for(int i = 1, j = 1; i <= n; i ++ )
    {
        while(j < n && a[j] ^ a[j + 1])
        {
            j ++ ;
        }
        segs.push_back({i, j});
        i = j ++;
    }
    // for(auto x : segs)
    // {
    //     cout << x.first << ' ' << x.second << endl;
    // }
    while(q -- )
    {
        int l, r;
        cin >> l >> r;
        if((r - l + 1) % 3 || (pre[r] - pre[l - 1]) % 3)
        {
            cout << -1 << endl;
            continue;
        }
        int l0 = 0, r0 = segs.size() - 1;
        while(l0 < r0)
        {
            int mid = (l0 + r0 + 1) >> 1;
            if(l >= segs[mid].first) l0 = mid;
            else r0 = mid - 1;
        }
        // cout << l << ' ' << r << ' ' << l0 << endl;
        if(segs[l0].first <= l && segs[l0].second >= r)
        {
            cout << (r - l + 1) / 3 + 1 << endl;
            continue;
        }
        cout << (r - l + 1) / 3 << endl;
    }
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