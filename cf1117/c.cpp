#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 2; i <= n; i ++ )
    {
        cin >> p[i];
    }
    int m;
    cin >> m;
    vector<int> a(m + 1);
    for(int i = 1; i <= m; i ++ )
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    cout << a.size() - 2 << ' ';
    for(int i = 2; i <= m; i ++ )
    {
        cout << a[i] << ' ';
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