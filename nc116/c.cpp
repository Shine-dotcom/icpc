#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> seg;
    
    for(int i = 1; i <= n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        seg.push_back({a, i});
        seg.push_back({b, i});
    }
    sort(seg.begin(), seg.end(), [&](pair<int, int> x, pair<int, int> y){
        return x.first < y.first;
    });
    while(q -- )
    {
        // cout << endl;
        int x, l = 0, r = seg.size() - 1;
        cin >> x;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(seg[mid].first <= x)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
            // cout << "l r " << l << ' ' << r << endl;
        }
        if(seg[l].first == x)
        {
            cout << seg[l].second << endl;
            continue;
        }
        if(seg[0].first <= x && seg[seg.size() - 1].first >= x && seg[l].second == seg[l + 1].second)
        {
            cout << seg[l].second << endl;
            continue;
        }
        cout << -1 << endl;
    }
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