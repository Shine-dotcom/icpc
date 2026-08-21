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
        cout << 1 << endl;
        return;
    }
    if(n == 2)
    {
        cout << 9 << endl;
        return;
    }
    if(n < 5)
    {
        cout << 4 * (n * n - 1) - n << endl;
        return;
    }
    cout << 5 * (n * n - 1 - n) << endl;
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