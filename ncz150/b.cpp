#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> a(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];
    sort(a.begin() + 1, a.end());
    sum -= a[n] - a[n - 1];
    cout << sum << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}