#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<int> stk;
    int mx = 0;
    for(int i = 1; i <= n; i ++ )
    {
        while(stk.size() && a[stk.back()] > a[i])
        {
            int cur = stk.back();
            stk.pop_back();
            int left = (stk.empty() ? 0 : stk.back());
            mx = max(mx, (i - left - 1) * a[cur]);
        }
        stk.push_back(i);
    }
    int m = stk.size();
    for(int i = -1; i < m; i ++ )
    {
        if(i == -1)
        {
            mx = max(mx, n * a[stk[i + 1]]);
            continue;
        }
        mx = max(mx, (n - stk[i]) * a[stk[i + 1]]);
    }
    cout << mx << endl;
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
    return 0;
}