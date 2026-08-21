#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    if(n % 2)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    cout << n / 2 << ' ' << n / 2 << endl;
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