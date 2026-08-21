#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    auto check = [&](int x, vector<int> t) -> int{
        int cnt = 0;
        for(int i = 1; i < n; i ++ )
        {
//            cout << "i " << i << endl;
            if(t[i] >= t[i + 1])
            {
                cnt += (t[i] - t[i + 1]) / x + 1; 
            }
//            cout << "cnt " << cnt << endl;
        }
        return cnt <= m;
    };
    int l = 1, r = 1e9 + 1;
    int flag = 1;
    for(int i = 1; i < n; i ++ )
    {
        if(a[i] >= a[i + 1]) flag = 0;
    }
    if(flag || n == 1)
    {
        cout << 0 << endl;
        return;
    }
    while(l != r)
    {
        int mid = (l + r) >> 1;
        if(check(mid, a)) r = mid;
        else l = mid + 1;
        // cout << "l r " << l << ' ' << r << endl;
    }
    cout << (check(r, a) ? r : -1) << endl;
	// cout << check(r, a) << ' ' << m << endl;
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