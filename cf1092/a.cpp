#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i] = min((a[i] % p) % q, (a[i] % q) % p);
        // cout << a[i] << ' ';
        a[i] += a[i - 1];
    }
    // cout << endl;
    cout << a[n] << endl;
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