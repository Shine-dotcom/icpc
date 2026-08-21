#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    if(m <= n - n / k)
    cout << (n / k + 1) / 2 + m << endl;
    else
    {
        int m0 = m - n + n / k;
        cout << n - ((n / k) - m0) / 2 << endl;
    }
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