#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    auto check = [&](int x) -> int {
        int res_p = 0, res_n = 0;
        for(int i = 1; i <= n; i ++ )
        {
            if(a[i] >= x) res_n += a[i] - x;
            else res_p += x - a[i];
        }
        if(res_n > res_p) return -1;
        return res_p;
    };
    sort(a.begin() + 1, a.end());
    int l = a[1], r = a[n];
    while(l + 1 < r)
    {
        int mid = (l + r) / 2;
        if(check(mid) == -1) l = mid;
        else r = mid;
        // cout << l << ' ' << r << endl;
    }
    cout << check(r) << endl;
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
    return 0;
}