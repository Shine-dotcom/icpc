#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct seg{
    int l, r;
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
    sort(a.begin() + 1, a.end());
    if(n == 1 || a[1] == a[n])
    {
        cout << -1 << endl;
        return;
    }
    int cntl = 0, cntr = 0;
    int x = (n + 1) / 2;
    for(int i = 1; i <= n; i ++ )
    {
        if(a[i] < a[x]) cntl ++;
        if(a[i] > a[x]) cntr ++;
    }
    int ans = n - 1;
    ans = min(ans, n - 2 * cntl);
    ans = min(ans, n - 2 * cntr + 1);
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
    return 0;
}