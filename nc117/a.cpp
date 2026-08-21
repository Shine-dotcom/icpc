#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int a, b;
    cin >> a >> b;
    if(a == 1 && b == 1)
    {
        cout << "LU" << endl;
        return;
    }
    if(a == 1 && b == 2)
    {
        cout << "LD" << endl;
        return;
    }
    if(a == 2 && b == 1)
    {
        cout << "RU" << endl;
        return;
    }
    if(a == 2 && b == 2)
    {
        cout << "RD" << endl;
        return;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t -- )
    {
        solve();
    }
}