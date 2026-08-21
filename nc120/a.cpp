#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        cout << 'a';
    }
    cout << 'b';
    for(int i = 1; i <= n; i ++ )
    {
        cout << 'a';
    }
    cout << endl;
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
