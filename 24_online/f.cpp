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
    vector<int> pre(n + 1), suf(n + 1);
    int cnt = 0;
    int ans = 0;
    int mx = 0;
    for(int i = 2; i <= n; i ++ )
    {
        if(a[i] > mx)
        {
            ans += (i - 1);
            pre[i] = 0;
            continue;
        }
        if(a[i] > a[i - 1]) pre[i] = pre[i - 1] + cnt + 1, cnt = 0, ans += pre[i];
        if(a[i] < a[i - 1])
        {
            pre[i] = 0;
        }
        if(a[i] == a[i - 1]) pre[i] = pre[i - 1], cnt ++;
        cout << pre[i] << ' ';
        mx = max(mx, a[i]);
    }
    cout << endl;
    cnt = 0;
    for(int i = n - 1; i >= 1; i -- )
    {
        if(a[i] > a[i + 1]) suf[i] = suf[i + 1] + cnt + 1, cnt = 0, ans += suf[i];
        if(a[i] < a[i + 1])
        {
            suf[i] = 0;
        }
        if(a[i] == a[i + 1]) suf[i] = suf[i + 1], cnt ++;
        cout << suf[i] << ' ';
    }
    cout << endl;
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