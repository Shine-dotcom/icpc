#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] -= c;
        if(a[i] > 0) cnt ++;
    }
    int p = max(cnt, (n + 1) / 2);
    sort(a.begin() + 1, a.end());
    int sum = 0;
    for(int i = n; i > n - p; i -- )
    {
        sum += a[i];
    }
    cout << sum << endl;
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