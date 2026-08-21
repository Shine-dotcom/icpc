#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
    int val, l = 0, r = 1e18;
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // for(int i = 1; i <= n; i ++ )
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    int ans = 1;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= i; j ++ )
        {
            int l1 = i, r1 = n;
            while(l1 < r1)
            {
                int mid = (l1 + r1 + 1) >> 1;
                if(a[mid] <= 2 * a[i] - a[j]) l1 = mid;
                else r1 = mid - 1;
                // cout << l << ' ' << r << endl;
            }
            int l2 = i, r2 = n;
            while(l2 < r2)
            {
                int mid = (l2 + r2) >> 1;
                if(a[mid] >= 2 * a[i] - a[j]) r2 = mid;
                else l2 = mid + 1;
                // cout << l << ' ' << r << endl;
            }
            int l = l2, r = l1;
            // cout << j << ' ' << i << ' ' << l << ' ' << r << endl;
            // cout << j << ' ' << i << ' ' << r << endl;
            // cout << a[j] << ' ' << a[i] << ' ' << a[r] << endl;
            // cout << j << ' ' << i << ' ' << ans << endl;
            if(a[r] != 2 * a[i] - a[j]) continue;
            // cout << "r - i: " << r - i << endl;
            // cout << "i - j: " << i - j << endl;
            // cout << j << ' ' << i << ' ' << l << ' ' << r << endl;
            if(r - i <= i - j)
            {
                // cout << 222 << endl;
                ans = max(ans, 2 * (r - i) + 1);
                continue;
            }
            // cout << 333 << endl;
            ans = max(ans, 2 * (i - j + 1));
        }
    }
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