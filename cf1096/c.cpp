#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), fac1, fac2, fac3, fac6;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        if(a[i] % 6 == 0)
        {
            fac6.push_back(a[i]);
            continue;
        }
        if(a[i] % 3 == 0)
        {
            fac3.push_back(a[i]);
            continue;
        }
        if(a[i] % 2 == 0)
        {
            fac2.push_back(a[i]);
            continue;
        }
        fac1.push_back(a[i]);
    }
    for(auto x : fac6)
    {
        cout << x << ' ';
    }
    for(auto x : fac3)
    {
        cout << x << ' ';
    }
    for(auto x : fac1)
    {
        cout << x << ' ';
    }
    for(auto x : fac2)
    {
        cout << x << ' ';
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