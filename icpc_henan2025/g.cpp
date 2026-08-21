#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    if(n == 2 || n == 4)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> a(n), b(n);
    for(int i = 1; i < n; i ++ )
    {
        a[i] = i, b[i] = i + 1;
    }
    int cnt = (n - 3) / 2;
    for(int i = 1; i <= cnt; i ++ )
    {
        int j = n - 2 * i + 1;
        a[j] = j - 1;
    }
    for(int i = 1; i < n; i ++ )
    {
        cout << a[i] << ' ' << b[i] << endl;
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