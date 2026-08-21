#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, T;
    cin >> n >> T;
    vector<int> h(n + 1), v(n + 1), sufmax(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> h[i];
    }
    for(int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
    }
    sufmax[n] = v[n];
    for(int i = n - 1; i >= 1; i -- )
    {
        sufmax[i] = max(sufmax[i + 1], v[i]);
    }
    vector<int> submax(n);
    int mx = v[n];
    for(int i = n - 1; i >= 1; i -- )
    {
        if(v[i] < mx && i < n - 1)
        {
            submax[i] = max(submax[i + 1], v[i]);
            continue;
        }
        if(v[i] >= mx)
        {
            submax[i] = mx;
            mx = v[i];
            continue;
        }
        submax[n - 1] = min(v[n], v[n - 1]);
    }
    cout << "submax:" << endl;
    // for(auto x : submax)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    // cout << "sufmax:" << endl;
    // for(auto x : sufmax)
    // {
    //     cout << x << ' ';
    // }
    // cout << endl;
    int sum = 0;
    while(T -- )
    {
        int x;
        cin >> x;
        int l = 1, r = n;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(h[mid] >= x) l = mid + 1;
            else r = mid;
            // cout << l << ' ' << r << endl;
        }
        if(h[r] >= x)
        {
            continue;
        }
        int m = r;
        if(m == n)
        {
            sum += sufmax[n];
            continue;
        }
        sum += submax[m] + sufmax[m];
    }
    cout << sum << endl;
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