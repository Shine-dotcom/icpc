#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int x, y;
    cin >> x >> y;
    if(x > y)
    {
        cout << "NO" << endl;
        return;
    }
    if(x == 0 && y % 2 == 0)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int cnt = (y - x) / 2;
    vector<int> a(x + y), b(x + y);
    for(int i = 1; i < x + y; i ++ )
    {
        a[i] = i;
        b[i] = i + 1;
    }
    for(int i = 1; i <= cnt; i ++ )
    {
        int j = x + y - 2 * i + 1;
        a[j] = a[j - 1];
    }
    for(int i = 1; i < x + y; i ++ )
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
}