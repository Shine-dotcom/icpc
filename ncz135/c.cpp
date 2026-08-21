#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if(n == 2)
    {
        if(a[1] < a[2])
        {
            cout << "YES" << endl;
            return;
        }
        cout << "NO" << endl;
        return;
    }
    if(n == 3)
    {
        if(a[1] < a[2] && a[2] < a[3])
        {
            cout << "YES" << endl;
            return;
        }
        if(a[1] > a[2] && a[2] > a[3])
        {
            cout << "YES" << endl;
            return;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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