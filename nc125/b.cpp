#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    while(q -- )
    {
        int k, x;
        cin >> k >> x;
        int l = 1, r = n;
        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            if(a[mid] < x) l = mid;
            else r = mid - 1;
        }
        if(a[1] >= x) l = 0;
        // cout << l << endl;
        cout << (l >= k ? "Yes" : "No") << endl;
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