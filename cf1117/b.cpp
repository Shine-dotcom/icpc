#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= m; i ++ ) cin >> b[i];
    int sum1 = 0, sum2 = 0;
    for(int i = 2; i <= n; i ++ )
    {
        sum1 += a[i - 1] - a[i] + 1;
    }
    for(int i = 2; i <= m; i ++ )
    {
        sum2 += b[i - 1] - b[i] + 1;
    }
    sum1 += a[n];
    sum2 += b[m];
    cout << (sum1 >= sum2 ? 1 : 2) << endl;
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