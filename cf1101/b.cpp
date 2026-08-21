#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int avg = a[1];
    for(int i = 1; i <= n; i ++ )
    {
        avg = min(avg, pre[i] / i);
        cout << avg << ' ';
    }
    cout << endl;
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